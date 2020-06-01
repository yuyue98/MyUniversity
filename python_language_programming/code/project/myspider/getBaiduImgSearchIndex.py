import urllib.request
import urllib.parse
import os
root = os.getcwd()
fp = urllib.request.urlopen(r'https://image.baidu.com/search/index?tn=baiduimage&ipn=r&ct=201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1543368875668_R&pv=&ic=0&nc=1&z=0&hd=0&latest=0&copyright=0&se=1&showtab=0&fb=0&width=&height=&face=0&istype=2&ie=utf-8&ctd=1543368875669%5E00_980X373&word=%E8%87%AA%E7%84%B6')
print(fp)
for i in fp:
	print(i)