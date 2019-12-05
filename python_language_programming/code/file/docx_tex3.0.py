import zipfile
import re
import os
import json
from xml.dom import minidom
try:
    import xml.etree.cElementTree as ET
except ImportError:
    import xml.etree.ElementTree as ET
    
# 读文件的函数
# 可以读取文本文件和json格式文件
def get_filetext(name='demo.txt',ftype='text'):
    try:
        if ftype=='text':
            with open(name,'r',encoding='utf-8') as text:
                data = text.read()
        elif ftype=='json':
            with open(name,'r',encoding='utf-8') as text:
                data=json.loads(text.read())
    except:
        print('文件读取发生异常！')
        return False
    return data

# 写文件的函数
# 可以保存文本文件和json格式文件
def put_filetext(data,name='demo.txt',ftype='text'):
    try:
        if ftype=='text':
            with open(name,'w',encoding='utf-8') as text:
                text.write(data)
        elif ftype=='json':
            with open(name,'w',encoding='utf-8') as text:
                text.write(json.dumps(data,indent=4))
    except:
        print('文件保存发生异常！')
        return False

# 读取当前目录下的docx文档并转化为xml格式文本并保存
def docx_xml(docxname):
    document = zipfile.ZipFile(docxname+'.docx')
    xml_content = document.read('word/document.xml')
    reparsed = minidom.parseString(xml_content)
    xmlbytes = reparsed.toprettyxml(indent="   " , encoding="utf-8")
    xmlstr = str(xmlbytes,encoding="utf-8")
    document.close()
    put_filetext(xmlstr,docxname+'.xml')
    return xmlstr

# 通过正则表达式匹配生成名称空间的字典
def get_documentdict(docxname):
    xmlstr = docx_xml(docxname)
    rexmlns = re.compile(r'xmlns:[^=]*="[^"]*"')
    xmlnslist = rexmlns.findall(xmlstr)
    xmlnslists = []
    for xmlns in xmlnslist:
        if xmlns not in xmlnslists:
            xmlnslists.append(xmlns)
    documentdict = {}
    for xmlns in xmlnslists:
        xmlns = xmlns[6:]
        value,key = xmlns.split('=')
        key = key.replace('"','{',1)
        key = key.replace('"','}',1)
        value += ':'
        documentdict[key] = value
    return documentdict

# 逆替换docx转成的xml格式文本中的命名空间
def tgattrs_rp(tg,attrs):
    for key,value in documentdict.items():
        if key in tg:
            tg = tg.replace(key,'')
        attrskeys = list(attrs.keys())
        l = len(attrskeys)
        for i in range(l):
            if key in attrskeys[i]:
                attr = attrskeys[i].replace(key,'')
                attrs[attr] = attrs.pop(attrskeys[i])
    return tg,attrs

# 将xml格式文本转存在嵌套字典中（json）（递归实现）
def xml_json(root):
    if len(root)==0:
        leaf = {}
        tg,attrs = tgattrs_rp(root.tag,root.attrib)
        leaf[tg] = attrs
        if root.text!=None:
            leaf['text'] = root.text
        return leaf
    else:
        limb = {}
        childs = {}
        for i in range(len(root)):
            childs[i] = xml_json(root[i])
        tg,attrs = tgattrs_rp(root.tag,root.attrib)
        limb[tg] = attrs
        limb['childs'] = childs
        return limb

# json格式化输出
def jsonprint(data):
    print(json.dumps(data,indent=4,ensure_ascii=False))

# 第一阶段（docx文档转存为json格式文本）主函数
def docx_json(fname):
    tree = ET.parse(fname+'.xml')
    root = tree.getroot()
    jsonstr = xml_json(root)
    put_filetext(jsonstr,fname+'.json','json')
    jsonstr = get_filetext(fname+'.json','json')
    return jsonstr

jsonlabel = {
'body':{'p':'段落','tbl':'表格','sectPr':'页眉页脚'},
'p':{'pPr':'段落格式','r':'普通内容','oMath':'段内公式','oMathPara':'行间公式','bookmarkStart':'','bookmarkEnd':''},
'pPr':{'jc':'是否居中','rPr':'字体格式','spacing':'除以240为行间距','ind':'','numPr':'','outlineLvl':'','tabs':'','pStyle':''},
'rPr':{'rFonts':'字体类型','sz':'除以2为字体尺寸','color':'字体颜色','szCs':''},
'r':{'rPr':'字体格式','t':'文本内容'},
'oMathPara':{'oMath':'段内公式'},
'oMath':{'r':'段落内容','sSup':'上标结构','d':'小括号结构'},
'sSup':{'sSupPr':'上标格式','e':'底','sup':'上标'},
'tbl':{'tblPr':'表格格式','tblGrid':'表格列尺寸','tr':'表格行内容'},
'tblPr':{'tblW':'表格总宽度','jc':'表格布局','tblBorders':'表格边框格式'},
'tblGrid':{'gridCol':'单列宽度'},
'tr':{'trPr':'行格式','tc':'列内容'},
'trPr':{'trHeight':'表格行行高','jc':'表格行布局'},
'tc':{'tcPr':'列格式','p':'段落'}
}

# 该函数仅区分body标签下的子标签，并按顺序存储
# 并没有实现子标签中数据的整理
def get_labellist(root):
    # 按一级标题对标签进行分类
    # 区别段落和表格
    # 按顺序存储在列表中
    # 为之后的二级标签的分类做准备
    labellist = [] 
    for i in root:
        labeldict ={}
        if 'p' in root[i]:
            labeldict['name'] = 'para'
            if 'childs' in root[i]:
                labeldict['text'] = root[i]['childs']
            else:
                labeldict['text'] = {}
        elif 'tbl' in root[i]:
            labeldict['name'] = 'table'
            if 'childs' in root[i]:
                labeldict['text'] = root[i]['childs']
            else:
                labeldict['text'] = {}
        if labeldict!={}:
            labellist.append(labeldict)
    return labellist

# 该函数仅区分p标签下的子标签，并按顺序存储
# 并没有实现子标签中数据的整理
def get_paradict(root):
    # 对段落一级标签的子标签进行分类
    # 区别段落格式、普通文本和公式
    # 按顺序存储相应内容
    # 为之后的段落中普通文本和公式内容识别做准备
    paradict = {}
    textdict = {}
    tid = 0
    for i in root:
        dic = {}
        # 段落格式
        if 'pPr' in root[i]:
            paradict['format'] = root[i]['childs']
        # 书签
        elif 'bookmarkStart' in root[i]:
            paradict['titleid'] = root[i]['bookmarkStart']['id']
        # 普通内容
        elif 'r' in root[i]:
            dic['name'] = 'text'
            dic['text'] = root[i]['childs']
        # 段内公式
        elif 'oMath' in root[i]:
            dic['name'] = 'form'
            dic['text'] = root[i]['childs']
        # 行间公式
        elif 'oMathPara' in root[i]:
            dic['name'] = 'form'
            for j in root[i]['childs']:
                if 'oMathParaPr' in root[i]['childs'][j]:
                    dic['format'] = get_parafmtdict(root[i]['childs'][j]['childs'])
                elif 'oMath' in root[i]['childs'][j]:
                    dic['text'] = root[i]['childs'][j]['childs']
        if dic!={}:
            textdict[tid] = dic
            tid += 1
    paradict['text'] = textdict
    return paradict

def get_parafmtdict(root):
    # 整理段落格式中的内容
    # 即处理pPr标签中的数据
    formatdict = {}
    formatdict['isCenter'] = False
    formatdict['isBold'] = False
    for i in root:
        # 段落布局（居中、居左、居右）
        if ('jc' in root[i]) and ('val' in root[i]['jc']) and (root[i]['jc']['val']=='center'):
            formatdict['isCenter'] = True
        # 行间距，其中存储的值除以240即为几倍行距
        elif 'spacing' in root[i]:
            if 'line' in root[i]['spacing']:
                formatdict['linespacing'] = int(int(root[i]['spacing']['line'])//240)
        # 文本格式（这里指段落默认字体格式）
        elif 'rPr' in root[i]:
            fontdict = get_fontdict(root[i]['childs'])
            # 字体
            if 'font' in fontdict:
                formatdict['font'] = fontdict['font']
            # 是否加粗
            if 'isBold' in fontdict:
                formatdict['isBold'] = fontdict['isBold']
            # 字号
            if 'size' in fontdict:
                formatdict['size'] = fontdict['size']
    return formatdict

def get_fontdict(root):
    # 整理字体格式中的内容
    # 处理rPr标签中的数据
    fontdict ={}
    fontdict['isBold'] = False
    for i in root:
        # 字体标签
        if 'rFonts' in root[i]:
            if 'ascii' in root[i]['rFonts']:
                fontdict['font'] = root[i]['rFonts']['ascii']
            elif 'eastAsia' in root[i]['rFonts']:
                fontdict['font'] = root[i]['rFonts']['eastAsia']
            else:
                fontdict['font'] = ''
        # 加粗标签
        elif 'b' in root[i]:
            fontdict['isBold'] = True
        elif ('sz' in root[i]) and ('val' in root[i]['sz']):
            fontdict['size'] = int(int(root[i]['sz']['val'])//2)
    return fontdict

def get_paratext(root):
    # 整理段落文本
    # 处理p标签中普通文本和公式内容数据
    for i in root:
        if root[i]['name']=='text':
            textdict = get_textdict(root[i]['text'])
            if 'format' in textdict:
                root[i]['format'] = textdict['format']
            if 'text' in textdict:
                root[i]['text'] = textdict['text']
        elif root[i]['name']=='form':
            root[i]['text'] = get_formdict(root[i]['text'])

def get_textdict(root):
    # 整理普通文本并提取相关内容
    # 处理r标签中的数据
    textdict = {}
    textdict['format'] = {}
    textdict['format']['isBold'] = False
    for i in root:
        # 文本格式
        if 'rPr' in root[i]:
            fontdict = get_fontdict(root[i]['childs'])
            if 'font' in fontdict:
                textdict['format']['font'] = fontdict['font']
            if 'isBold' in fontdict:
                textdict['format']['isBold'] = fontdict['isBold']
            if 'size' in fontdict:
                textdict['format']['size'] = fontdict['size']
        # 文本内容
        elif 't' in root[i]:
            textdict['text'] = root[i]['text']
    return textdict

def get_formdict(root):
    # 整理并提取公式相关内容
    formdict = {}
    tid = 0
    for i in root:
        dic = {}
        # 普通内容
        if 'r' in root[i]:
            dic['name'] = 'text'
            textdict = get_textdict(root[i]['childs'])
            if 'text' in textdict:
                dic['text'] = textdict['text']
            if 'format' in textdict:
                dic['format'] = textdict['format']
        # 上标
        elif 'sSup' in root[i]:
            dic['name'] = 'sup'
            dic['text'] = get_supdict(root[i]['childs'])
        # 小括号
        elif 'd' in root[i]:
            dic['name'] = 'cur'
            dic['text'] = get_curdict(root[i]['childs'])
        if dic!={}:
            formdict[tid] = dic
            tid += 1
    return formdict

def get_ctrldict(root):
    # 整理并提取公式内部部件格式内容
    ctrldict = {}
    ctrldict['format'] = {}
    ctrldict['format']['isBold'] = False
    for i in root:
        if 'ctrlPr' in root[i]:
            for j in root[i]['childs']:
                if 'rPr' in root[i]['childs'][j]:
                    fontdict = get_fontdict(root[i]['childs'][j]['childs'])
                    if 'font' in fontdict:
                        ctrldict['format']['font'] = fontdict['font']
                    if 'isBold' in fontdict:
                        ctrldict['format']['isBold'] = fontdict['isBold']
                    if 'size' in fontdict:
                        ctrldict['format']['size'] = fontdict['size']
    return ctrldict

def get_supdict(root):
    # 整理并提取公式上标结构的内容
    supdict = {}
    for i in root:
        # 上标结构格式
        if 'sSupPr' in root[i]:
            ctrldict = get_ctrldict(root[i]['childs'])
            if 'format' in ctrldict:
                supdict['format'] = ctrldict['format']
        # 上标结构底
        elif 'e' in root[i]:
            for j in root[i]['childs']:
                if 'r' in root[i]['childs'][j]:
                    supdict['e'] = get_textdict(root[i]['childs'][j]['childs'])
        # 上标格式幂
        elif 'sup' in root[i]:
            for j in root[i]['childs']:
                if 'r' in root[i]['childs'][j]:
                    supdict['sup'] = get_textdict(root[i]['childs'][j]['childs'])
    return supdict

def get_curdict(root):
    # 整理并提取公式小括号结构的内容
    curdict = {}
    for i in root:
        # 小括号结构格式
        if 'dPr' in root[i]:
            ctrldict = get_ctrldict(root[i]['childs'])
            if 'format' in ctrldict:
                curdict['format'] = ctrldict['format']
        # 小括号结构底
        elif 'e' in root[i]:
            for j in root[i]['childs']:
                if 'r' in root[i]['childs'][j]:
                    curdict['e'] = get_textdict(root[i]['childs'][j]['childs'])
    return curdict

# 该函数仅区分tbl标签下的子标签，并按顺序存储
# 并没有实现子标签中数据的整理
def get_tabledict(root):
    # 整理表格中的内容
    tabledict = {}
    tableline = {}
    tid = 0
    for i in root:
        # 表格格式
        if 'tblPr' in root[i]:
            tabledict['format'] = root[i]['childs']
        # 表格列尺寸
        elif 'tblGrid' in root[i]:
            tabledict['size'] = root[i]['childs']
        # 表格行内容
        elif 'tr' in root[i]:
            tableline[tid] = root[i]['childs']
            tid += 1   
    tabledict['text'] = tableline
    return tabledict

def get_tblfmtdict(root):
    # 整理表格格式中的内容
    # 即处理tblPr标签中的数据
    formatdict = {}
    formatdict['isCenter'] = False
    formatdict['isTopline'] = True
    formatdict['isLeftline'] = True
    formatdict['isBottomline'] = True
    formatdict['isRightline'] = True
    formatdict['isInsidehline'] = True
    formatdict['isInsidevline'] = True
    for i in root:
        # 表格总宽度
        if ('tblW' in root[i]) and ('w' in root[i]['tblW']):
            formatdict['tblw'] = int(int(root[i]['tblW']['w'])//567)
        # 表格布局（居中、居左、居右）
        elif ('jc' in root[i]) and ('val' in root[i]['jc']) and (root[i]['jc']['val']=='center'):
            formatdict['isCenter'] = True
        # 表格线
        elif 'tblBorders' in root[i]:
            for j in root[i]['childs']:
                if ('top' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['top']) and (root[i]['childs'][j]['top']['sz']=='0'):
                    formatdict['isTopline'] = False
                elif ('left' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['left']) and (root[i]['childs'][j]['left']['sz']=='0'):
                    formatdict['isLeftline'] = False
                elif ('bottom' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['bottom']) and (root[i]['childs'][j]['bottom']['sz']=='0'):
                    formatdict['isBottomline'] = False
                elif ('right' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['right']) and (root[i]['childs'][j]['right']['sz']=='0'):
                    formatdict['isRightline'] = False
                elif ('insideH' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['insideH']) and (root[i]['childs'][j]['insideH']['sz']=='0'):
                    formatdict['isInsidehline'] = False
                elif ('insideV' in root[i]['childs'][j]) and ('sz' in root[i]['childs'][j]['insideV']) and (root[i]['childs'][j]['insideV']['sz']=='0'):
                    formatdict['isInsidevline'] = False
    return formatdict

def get_tblszdict(root):
    # 整理表格列尺寸中的内容
    # 即处理tblGrid标签中的数据
    tblszdict = {}
    sizedict = {}
    tblszdict['len'] = 0
    tblszdict['tblw'] = 0
    for i in root:
        if ('gridCol' in root[i]) and ('w' in root[i]['gridCol']):
            sizedict[tblszdict['len']] = int(root[i]['gridCol']['w'])/567.0
            tblszdict['tblw'] += sizedict[tblszdict['len']]
            sizedict[tblszdict['len']] = float('%.2f' % sizedict[tblszdict['len']])
            tblszdict['len'] += 1
    tblszdict['tblw'] = float('%.2f' % tblszdict['tblw'])
    tblszdict['size'] = sizedict
    return tblszdict

def get_tbltext(root):
    tctextdict = {}
    for i in root:
        tctext = {}
        formatdict = {}
        tid = 0
        tcid = 0
        for j in root[i]:
            if 'trPr' in root[i][j]:
                formatdict = get_trfmtdict(root[i][j]['childs'])
            elif 'tc' in root[i][j]:
                tctext[tid] = get_tctext(root[i][j]['childs'],tctextdict,tcid)
                if 'gridSpan' in tctext[tid]:
                    tcid += tctext[tid]['gridSpan']
                else:
                    tcid += 1
                tid += 1
        root[i] = {}
        root[i]['format'] = formatdict
        root[i]['text'] = tctext

def get_trfmtdict(root):
    # 整理表格行内容格式中的内容
    # 即处理trPr标签中的数据
    formatdict = {}
    formatdict['isCenter'] = False
    for i in root:
        if ('trHeight' in root[i]) and ('val' in root[i]['trHeight']):
            formatdict['trh'] = int(root[i]['trHeight']['val'])
        elif ('jc' in root[i]) and ('val' in root[i]['jc']) and (root[i]['jc']['val']=='center'):
            formatdict['isCenter'] = True
    return formatdict

def get_tctext(root,tcdic,tcid):
    tctext = {}
    text = {}
    tid = 0
    #print(tcid)
    for i in root:
        dic = {}
        if 'tcPr' in root[i]:
            for j in root[i]['childs']:
                if ('tcW' in root[i]['childs'][j]) and ('w' in root[i]['childs'][j]['tcW']):
                    tctext['tcw'] = float('%.2f' % (int(root[i]['childs'][j]['tcW']['w'])/567))
                elif ('gridSpan' in root[i]['childs'][j]) and ('val' in root[i]['childs'][j]['gridSpan']):
                    tctext['gridspan'] = int(root[i]['childs'][j]['gridSpan']['val'])
                elif 'vMerge' in root[i]['childs'][j]:
                    if ('val' not in root[i]['childs'][j]['vMerge']):
                        if (tcid in tcdic) and ('vmerge' in tcdic[tcid]):
                            tcdic[tcid]['vmerge'] += 1 
                    elif root[i]['childs'][j]['vMerge']['val']=='restart':
                        tctext['vmerge'] = 1
                        tcdic[tcid] = tctext
        elif 'p' in root[i]:
            dic['name'] = 'para'
            paradict = get_paradict(root[i]['childs'])
            if 'format' in paradict:
                dic['format'] = get_parafmtdict(paradict['format'])
            if 'titleid' in paradict:
                dic['titleid'] = paradict['titleid']
            if 'text' in paradict:
                dic['text'] = paradict['text']
                get_paratext(dic['text'])
        if dic!={}:
            text[tid] = dic
            tid += 1
    tctext['text'] = text
    return tctext

# 第二阶段（json格式文本进行完数据处理）函数
def json_dict(fname):
    # 第一遍处理（仅区分段落和表格，并按顺序存储）
    labellist = get_labellist(jsonstr['childs']['0']['childs'])
    demodict = {}
    # 第二遍处理（对段落和表格中的内容进行预处理）
    for i in range(len(labellist)):
        dic = labellist[i]
        if dic['name']=='para':
            if dic['text']=={}:
                continue
            paradict = get_paradict(dic['text'])
            # 段落第三遍处理（实际实现对段落数据的处理）
            if 'format' in paradict:
                dic['format'] = get_parafmtdict(paradict['format'])
            if 'titleid' in paradict:
                dic['titleid'] = paradict['titleid']
            if 'text' in paradict:
                dic['text'] = paradict['text']
                get_paratext(dic['text'])
        elif dic['name']=='table':
            tabledict = get_tabledict(dic['text'])
            # 表格第三遍处理（实际实现对表格数据的处理）
            if 'format' in tabledict:
                dic['format'] = get_tblfmtdict(tabledict['format'])
            if 'size' in tabledict:
                tblszdict = get_tblszdict(tabledict['size'])
                if 'tblw' in tblszdict:
                    dic['format']['tblw'] = tblszdict['tblw']
                if 'len' in tblszdict:
                    dic['format']['col'] = tblszdict['len']
                if 'size' in tblszdict:
                    dic['format']['size'] = tblszdict['size']
            if 'text' in tabledict:
                dic['format']['row'] = len(tabledict['text'])
                dic['text'] = tabledict['text']
                get_tbltext(dic['text'])
    put_filetext(labellist,fname+'1'+'.json','json')
    labels = get_filetext(fname+'1'+'.json','json')
    return labels

def get_texpara(text,fmtdic={}):
    # 将段落内容（p标签内容）转化成latex文本
    parastr = ''
    for i in text:
        textstr = ''
        if 'format' in text[i]:
            formatdict = text[i]['format']
        else:
            formatdict = fmtdic
        if text[i]['name']=='text':
            textstr = get_textext(text[i]['text'],formatdict)
        elif text[i]['name']=='form':
            textstr = get_texform(text[i]['text'],formatdict)
        parastr += textstr
    return parastr

def get_textext(text,fmtdic={}):
    # 将普通文本内容（r标签内容）转化成latex文本
    b = re.compile('%')
    text = re.sub(b,'\%',text)
    b = re.compile(' ')
    text = re.sub(b,'\\quad ',text)
    b = re.compile('<<')
    text = re.sub(b,'《 ',text)
    b = re.compile('>>')
    text = re.sub(b,'》 ',text)
    textstr = get_texformat(text,fmtdic)
    return textstr

def get_texform(text,fmtdic={}):
    # 将公式内容（r标签内容）转化成latex文本
    formstr = '$'
    for i in text:
        textstr = ''
        if 'format' in text[i]:
            formatdict = text[i]['format']
        else:
            formatdict = fmtdic
        # 公式普通文本转化
        if text[i]['name']=='text':
            textstr = get_textext(text[i]['text'],formatdict)
        # 公式小括号结构文本转化
        elif text[i]['name']=='cur':
            if 'format' in text[i]['text']['e']:
                eformat = text[i]['text']['e']['format']
            else:
                if 'format' in text[i]['text']:
                    curformat = text[i]['text']['format']
                else:
                    curformat = formatdict
                eformat = curformat
            textstr = '('+get_textext(text[i]['text']['e']['text'],eformat)+')'
        # 公式上标结构文本转化（未实现）
        elif text[i]['name']=='sup':
            pass
        formstr += textstr
    formstr += '$'
    if 'format' not in text:
        formstr = get_texformat(formstr,fmtdic)
    else:
        formstr = get_texformat(formstr,text['format']) 
    return formstr

def get_textable(text,fmtdic={}):
    # 将表格内容（tbl标签内容）转化成latex文本
    tablestr = '\\begin{tabular}\n'
    tblfmt = '{'
    if fmtdic['isLeftline']:
        tblfmt += '|'
    for i in range(fmtdic['col']):
        tblfmt += 'p{'+str(fmtdic['size'][str(i)])+'cm}'
        if fmtdic['isCenter']:
            tblfmt += '<{\centering}'
        if i!=fmtdic['col']-1 and fmtdic['isInsidevline']:
            tblfmt += '|'
    if fmtdic['isLeftline']:
        tblfmt += '|}\n'
    else:
        tblfmt += '}\n'
    tablestr += tblfmt
    if fmtdic['isTopline']:
        tablestr += '\\hline\n'
    #textlist = []
    for i in text:
    # 遍历行
        textstr = ''
        lie = 1
        a = ''
        b = ''
        flag = 0
        l = len(text[i]['text'])
        for j in text[i]['text']:
        # 遍历列
            if 'gridspan' in text[i]['text'][j]:
                if i!=str(fmtdic['row']-1):
                    a += '\\multicolumn{'+str(text[i]['text'][j]['gridspan'])+'}{|c|}'
                    b += '\\cline{'+str(lie)+'-'
                    lie = lie + text[i]['text'][j]['gridspan'] - 1
                    b += str(lie)+'} '
                    flag = 1
                else:
                    a += '\\multicolumn{'+str(text[i]['text'][j]['gridspan'])+'}{|l|}'
                    flag = 1
            elif 'vmergr' in text[i]['text'][j]:
                a += '\\multirow{'+str(text[i]['text'][j]['vmergr'])+'}*'
            lie += 1
            for k in text[i]['text'][j]['text']:
            # 遍历单元格中元素
                if text[i]['text'][j]['text'][k]['name']=='para':
                    a += '{'+get_texpara(text[i]['text'][j]['text'][k]['text'])+'}'
                elif text[i]['text'][j]['text'][k]['name']=='table':
                    pass
            if j!=str(l-1):
                a += '&'
            else:
                textstr += a + '\\\\' + b + '\n'
        tablestr += textstr
        if i!=str(fmtdic['row']-1) and fmtdic['isInsidevline'] and flag!=1:
            tablestr += '\\hline\n'
    if fmtdic['isBottomline']:
        tablestr += '\\hline\n'
    tablestr += '\\end{tabular}'
    return tablestr

def get_texformat(text,fmtdic):
    # 在latex中设置相应文本格式
    if 'font' in fmtdic:
        text = put_fonttype(text,fmtdic['font'])
    if 'size' in fmtdic:
        if 'line' in fmtdic:
            text = put_fontsize(text,fmtdic['size'],fmtdic['line'])
        else:
            text = put_fontsize(text,fmtdic['size'])
    if 'isBold' in fmtdic and fmtdic['isBold']:
        text = put_bold(text)
    if 'isCenter' in fmtdic and fmtdic['isCenter']:
        text = put_center(text)
    return text

def put_fonttype(text,fonttype):
    # 在latex中设置文本字体类型
    typestr = ''
    if '宋体' in fonttype:
        typestr = '\\songti '
    elif '黑体' in fonttype:
        typestr = '\\heiti '
    elif '仿宋' in fonttype:
        typestr = '\\fangsong '
    elif '楷体' in fonttype:
        typestr = '\\kaishu '
    textstr = '{'+typestr+text+'}'
    return textstr

def put_fontsize(text,fontsize,linesize='1'):
    # 在latex中设置文本字体大小
    fontstr = '{'+str(fontsize)+'}'
    linestr = '{'+str(linesize)+'}'
    textstr = '{'+'\\fontsize'+fontstr+linestr+'\n'+text+'}'
    return textstr

def put_bold(text):
    # 在latex中设置文本加粗
    textstr = '\\textbf {\n'+text+'}'
    return textstr

def put_center(text):
    # 在latex中设置文本居中
    textstr = '\\centerline {\n'+text+'}'
    return textstr

# 第三阶段（读取数据处理后的字典，转化为latex格式文本）函数
def dict_tex(fname):
    latexstr = '''\\documentclass[UTF8]{ctexart}
\\usepackage{mathbbold}
\\usepackage{CJK,CJKnumb}
\\usepackage{indentfirst}                 % 首行缩进宏包
\\usepackage{latexsym,bm}                 % 处理数学公式中和黑斜体的宏包
\\usepackage{amsmath,amssymb,amsfonts}    % AMSLaTeX宏包 用来排出更加漂亮的公式
\\usepackage{array}                       % 用于表格内容居中
\\usepackage{graphicx}
\\usepackage{multirow}
\\usepackage{cases}
\\usepackage{pifont}
\\usepackage{txfonts}
\\begin{document}
'''
    for i in labels:
        text = ''
        if 'format' in i:
            formatdict = i.get('format')
        else:
            formatdict = {}
        if i.get('name')=='para':
            text = get_texpara(i.get('text'),formatdict)
        elif i.get('name')=='table':
            text = get_textable(i.get('text'),formatdict)
        if 'isCenter' in formatdict and formatdict['isCenter']:
            text = '\\begin{center}\n'+text+'\\end{center}'
        latexstr += text+'\\par '
    latexstr += '\\end{document}'
    put_filetext(latexstr,fname+'.tex')
    latexs = get_filetext(fname+'.tex')
    return latexs

def tex_pdf(fname):
    os.system('del *.bib *.blg *.bbl *.aux *.log *.brf *.nlo *.out *.dvi *.ps *.lof *.toc *.fls *.fdb_latexmk *.pdfsync *.synctex*.gz *.ind *.ilg *.idx')
    os.system('pdflatex '+fname+'.tex')
    os.system('del *.bib *.blg *.bbl *.aux *.log *.brf *.nlo *.out *.dvi *.ps *.lof *.toc *.fls *.fdb_latexmk *.pdfsync *.synctex*.gz *.ind *.ilg *.idx')


if __name__ == '__main__':
    while True:
        docxname = input('请输入文件名：').replace(' ','')
        if docxname=='quit':
            break
        fname,ftype = os.path.splitext(docxname)
        if ftype!='.docx':
            print('文件格式不正确，请使用后缀为.docx的文件')
        else:
            #生成名称空间的字典
            documentdict = get_documentdict(fname)
            jsonstr = docx_json(fname)
            labels = json_dict(fname)
            latexs = dict_tex(fname)
            tex_pdf(fname)
            
