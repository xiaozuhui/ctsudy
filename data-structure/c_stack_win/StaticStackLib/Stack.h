#pragma once

#define DEFAULT_COUNT 0  // 默认的元素个数
#define DEFAULT_SIZE 100  // 默认的长度
#define BLOCK_SIZE 20  // 每次申请的内存区块大小
#define CHAR_SIZE sizeof('a')  // 一个字符的大小
#define FAIL -1

class Stack
{
public:
	int Count;  // 元素个数
	int Size;  // 栈的空间大小
	char* Items;  // 元素数据
public:
	/// <summary>
	/// 默认构造函数
	/// </summary>
	Stack();

	/// <summary>
	/// 构造函数
	/// 将字符串的每一个字符压入栈内
	/// </summary>
	/// <param name="chs"></param>
	Stack(const char* chs);

	/// <summary>
	/// 申请内存空间
	/// </summary>
	/// <param name="n"></param>
	/// <returns></returns>
	bool ExtendSize(int n);

	/// <summary>
	/// 弹栈
	/// </summary>
	/// <returns></returns>
	char Pop();

	/// <summary>
	/// 入栈
	/// </summary>
	/// <param name="c"></param>
	/// <returns></returns>
	int Push(char c);

	/// <summary>
	/// 多元素入栈
	/// </summary>
	/// <param name="chs"></param>
	/// <returns></returns>
	int PushItems(const char* chs);

	/// <summary>
	/// 获取栈最底部（index = 0）的值
	/// </summary>
	/// <returns></returns>
	char Peek();

	/// <summary>
	/// 获取最上层（index = -1）的值
	/// </summary>
	/// <returns></returns>
	char PeekLast();
};

