#include "pch.h"
#include "Stack.h"
#include <stdlib.h>
#include <string.h>

Stack::Stack()
{
	this->Count = DEFAULT_COUNT;
	this->Size = DEFAULT_SIZE;
	this->Items = (char*)malloc((int)(DEFAULT_SIZE / BLOCK_SIZE) * BLOCK_SIZE * CHAR_SIZE);
}

Stack::Stack(const char* chs)
{
	this->Count = DEFAULT_COUNT;
	this->Size = DEFAULT_SIZE;
	this->Items = (char*)malloc((int)(DEFAULT_SIZE / BLOCK_SIZE) * BLOCK_SIZE * CHAR_SIZE);
	if (this->Items == NULL) {
		return;
	}
	if (chs == NULL) {
		return;
	}
	// 判断chs的长度是否超过了BLOCK_SIZE
	int len = (int)strlen(chs);
	int surplus = this->Size - this->Count;
	if (len > surplus) {
		bool success = this->ExtendSize(BLOCK_SIZE * ((int)((len - surplus) / BLOCK_SIZE) + 1));
		if (!success) {
			len = this->Size - this->Count;
		}
	}
	for (int i = 0; i < len; i++)
	{
		this->Items[i] = chs[i];
	}
	this->Count = len;
}

bool Stack::ExtendSize(int n)
{
	char* p = (char*)realloc(this->Items, n * CHAR_SIZE);
	if (p != NULL)
	{
		*this->Items = *p;
		this->Size += n;
		return true;
	}
	return false;
}

char Stack::Pop()
{
	if (this->Count == 0) {
		return '\0';
	}
	char lastItem = this->Items[this->Count - 1];
	this->Items[this->Count - 1] = '\0';
	this->Count -= 1;
	if (this->Count <= DEFAULT_SIZE && this->Size > DEFAULT_SIZE) {
		char* p = this->Items;
		this->Items = (char*)malloc(DEFAULT_SIZE * CHAR_SIZE);
		if (this->Items == NULL || this->Items == p)
		{
			return '\0';
		}
		for (int i = 0; i < this->Count; i++) {
			this->Items[i] = p[i];
		}
		free(p);
		this->Size = DEFAULT_SIZE;
	}
	return lastItem;
}

int Stack::Push(char c)
{
	if (this->Count + 1 > this->Size) {
		bool success = this->ExtendSize(BLOCK_SIZE);
		if (!success) {
			return FAIL;
		}
	}
	this->Items[this->Count] = c;
	this->Count++;
	return this->Count;
}

int Stack::PushItems(const char* chs)
{
	int len = (int)strlen(chs);
	int surplus = this->Size - this->Count;
	if (surplus < len) {
		bool success = this->ExtendSize(BLOCK_SIZE * ((int)((len - surplus) / BLOCK_SIZE) + 1));
		if (!success) {
			return FAIL;
		}
	}
	for (int i = 0; i < len; i++) {
		this->Items[this->Count + i] = chs[i];
	}
	this->Count += len;
	return this->Count;
}

char Stack::Peek()
{
	if (this->Count > 0 && this->Size > 0) {
		return this->Items[0];
	}
	else {
		return '\0';
	}
}

char Stack::PeekLast()
{
	if (this->Count > 0 && this->Size > 0) {
		return this->Items[this->Count - 1];
	}
	else {
		return '\0';
	}
}
