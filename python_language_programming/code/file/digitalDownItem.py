def qwe(n):
	if n == 1 or n==0:
		print(n)
		return
	for i in range(2,n+1):
		times = 0
		flag = 0
		if n%i!=0:
			continue
		while n%i==0:
			if not flag:
				print(str(i)+'^',end='')
				flag += 1
			times += 1
			n = (int)(n/i)
		print(times,end='')
		if n == 1:
			flag += 1
			break
		if flag == 1:
			print('*',end='')
	print()
qwe(1)
qwe(45)