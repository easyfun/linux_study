####待解决问题
1.函数多返回值初始化table
	function foo0() end
	function foo1() return 'a' end
	function foo2() return 'a','b' end

	d={foo0(),foo2(),4}
	print("table d")
	for i,v in ipairs(d) do
		print(i,v)
	end

	print("table d all")
	print(d[1], d[2], d[3], d[4], d[5], d[6])

	print("table d.keys")
	for key in pairs(d) do
		print(key)
	end

result:
	table d
	table d all
	nil a 4 nil nil nil
	table d.keys
	2
	3


####小结
函数参数对table，引用传递