/*
 * pnew.cpp
 *
 *  Created on: 24 Dec 2011
 *      Author: Andy Brown
 */

/**
 * Global placement operator new
 */

void* operator new(size_t size_,void *ptr_)
{
	return ptr_;
}

void operator delete(void *ptr_, size_t size_)
{
    free(ptr_);
}

