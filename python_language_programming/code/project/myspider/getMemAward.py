import requests, os
'''
目前该网址已失效，需使用最新网址
'''
dirpath = os.getcwd()+'/mem'
if not os.path.isdir(dirpath):
    os.mkdir(dirpath)

for i in range(100):
	num = 1900002+i
    filename = str(num)+'.pdf'
	filepath = os.path.join(dirpath, filename)
	url = 'http://www.comap-math.com/mcm/2019Certs/' +filename
	print("downloading with requests")
	r = requests.get(url) 
	print(url)
	with open(filepath, "wb") as code:
		code.write(r.content)