# your code goes here
mod=1298074214633706835075030044377087
val=[1]+[None]*500
for i in range(1,501):
	val[i]=(val[i-1]<<1)+1
	if(val[i]>mod):
		val[i]=val[i]-mod
t=int(raw_input())
for i in range(t):
	print val[int(raw_input())]
