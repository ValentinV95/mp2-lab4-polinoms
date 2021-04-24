#pragma once
template<typename T>
struct Node
{
	T data;
	Node* prev, * next;
};
