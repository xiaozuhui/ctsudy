#include <stdio.h>
#include "Stack.h"

int main() {
    Stack s = InitStack("abcdefghijklnmopq");
    Print(&s);

    char a = Pop(&s);
    printf("pop item: %c\n", a);
    a = Pop(&s);
    printf("pop item: %c\n", a);
    Print(&s);
    Push(&s, 'W');
    Push(&s, 'W');
    Push(&s, 'W');
    Print(&s);
    PushItems(&s, "123456781932946736912863981267845787832643487164917");
    Print(&s);
    printf("peek item: %c\n", Peek(&s, 0));
    printf("peek item: %c\n", Peek(&s, -1));
    printf("peek item: %c\n", Peek(&s, 8));
    Delete(&s);
    Print(&s);
    ReInitStack(&s);
    Push(&s, 'W');
    Push(&s, 'W');
    Push(&s, 'W');
    Print(&s);
    return 0;
}

/**
 * 结果：
/mnt/d/codes/data-structure/use_c_stack/cmake-build-debug/cds
堆栈大小：35
堆栈元素个数：17
堆栈元素如下：
-------
a	b	c	d
e	f	g	h
i	j	k	l
n	m	o	p
q
-------
pop item: q
pop item: p
堆栈大小：15
堆栈元素个数：15
堆栈元素如下：
-------
a	b	c	d
e	f	g	h
i	j	k	l
n	m	o
-------
堆栈大小：35
堆栈元素个数：18
堆栈元素如下：
-------
a	b	c	d
e	f	g	h
i	j	k	l
n	m	o	W
W	W
-------
堆栈大小：75
堆栈元素个数：69
堆栈元素如下：
-------
a	b	c	d
e	f	g	h
i	j	k	l
n	m	o	W
W	W	1	2
3	4	5	6
7	8	1	9
3	2	9	4
6	7	3	6
9	1	2	8
6	3	9	8
1	2	6	7
8	4	5	7
8	7	8	3
2	6	4	3
4	8	7	1
6	4	9	1
7
-------
peek item: a
peek item: 7
peek item: �
堆栈大小：0
堆栈元素个数：0
堆栈元素如下：
-------

-------
堆栈大小：15
堆栈元素个数：3
堆栈元素如下：
-------
W	W	W
-------

Process finished with exit code 0

 */
