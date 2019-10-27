
it = find(v.begin(),v.end(),element);

template<class InputIterator,class T>
InputIterator find(InputIterator first,InputIterator last,const T &value)
{
	while(first != end)
	{
		if(*first == value)
		{
			return first;
		}

		first++;
	}

	return last;
}

==========================================================================

int x = count(v.begin(),v.end(),element);

template<class InputIterator,class T>
int count(InputIterator first,InputIterator last,const T &value)
{
	int cnt = 0;
	while(first != end)
	{
		if(*first == value)
		{
			cnt++;
			return cnt;
		}

		first++;
	}

	return cnt;
}


