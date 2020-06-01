import requests
import os
from faker import Faker

def imgUrls(keyWord, userAgent, pn=0, rn=30):
    url = 'https://image.baidu.com/search/acjson'
    params = {
        'tn': 'resultjson_com',
        'ipn': 'rj',
        'ct': '201326592',
        'is': '',
        'fp': 'result',
        'queryWord': keyWord,
        'cl': 2,
        'lm': -1,
        'ie': 'utf-8',
        'oe': 'utf-8',
        'adpicid': '',
        'st': -1,
        'z': 0,
        'ic': 0,
        'hd': 0,
        'latest': 0,
        'copyright': 0,
        'word': keyWord,
        's': '',
        'se': '',
        'tab': '',
        'width': '',
        'height': '',
        'face': 0,
        'istype': 2,
        'qc': '',
        'nc': 1,
        'fr': '',
        'expermode': '',
        'selected_tags': '',
        'cg': 'girl',
        'pn': pn,
        'rn': rn,
        'gsm': '1e',
        '1543417707210': ''
    }
    rep = requests.get(url, headers={'User-Agent': userAgent}, params=params)
    if(int(rep.status_code) == 200):
        try:
            imgs = rep.json()
            """解析返回的url地址"""
            def decodeUrl(imgUrl):
                longDic={'_z2C$q': ":",'_z&e3B': ".",'AzdH3F': "/"}
                mapDic={'w': "a",'k': "b",'v': "c",'1': "d",'j': "e",'u': "f",'2': "g",'i': "h",'t': "i",'3': "j",'h': "k",'s': "l",'4': "m",'g': "n","5": "o",'r': "p",'q': "q","6": "r",'f': "s",'p': "t","7": "u",'e': "v",'o': "w","8": "1",'d': "2",'n': "3","9": "4",'c': "5",'m': "6","0": "7",'b': "8",'l': "9",'a': "0"}
                for k in longDic:
                    imgUrl=imgUrl.replace(k,longDic[k])
                imgUrl=list(imgUrl)
                tmp=[]
                for i in imgUrl:
                    if i in mapDic:
                        tmp.append(mapDic[i])
                    else:
                        tmp.append(i)
                return ''.join(tmp)
            imgUrls = [decodeUrl(imgs['data'][sec]['objURL'])
                for sec in range(len(imgs['data']) - 1)]
            result = imgUrls
            status = True
        except Exception as err:
            result = str(err)
            status = False
        finally:
            return {'result': result, 'status': status}


if __name__ == '__main__':
    fake = Faker(locale='zh-CN')
    dirpath = os.getcwd()+'/img'
    if not os.path.isdir(dirpath):
    	os.mkdir(dirpath)
    keyword = input('input a key:')
    urls = imgUrls(keyWord=keyword, userAgent=fake.user_agent())
    if urls['status']:
    	index = 1
    	for url in urls['result']:
    		print("Downloading:", url)
    		try:
    			res = requests.get(url)
    			if str(res.status_code)[0] == "4":
    				print("未下载成功：", url)
    				continue
    		except Exception as e:
    			print("未下载成功：", url)
    		filename = os.path.join(dirpath, keyword+str(index) + ".jpg")
    		with open(filename, 'wb') as f:
    			f.write(res.content)
    			index += 1
    print(index)