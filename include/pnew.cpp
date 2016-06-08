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
