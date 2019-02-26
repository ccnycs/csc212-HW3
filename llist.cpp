

		// ANSWER BELOW!!!!!!!!
		// ######################
		// ######################
		// ######################
		// ######################

		size_t length()
		// Library facilities used: cstdlib
		{
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = this; cursor != NULL; cursor = cursor->link( ))
			++answer;
		
		return answer;
		}

		value_type val_at(int ind)
		{
			if ( ind >= this->length() ) 
				return NULL; 

			node* cur = this;
			for ( int i = 0; i < ind; i++ )
				cur = cur->link_field;
			return cur->data();			
		}

		node* operator[] (size_t ind)
		{
			if ( ind >= this->length() ) 
				return NULL; 

			node* cur = this;
			for ( int i = 0; i < ind; i++ )
				cur = cur->link_field;
			return cur;
		}

		nodespace::node& operator = (node::value_type i)
		{
			set_data(i);
			return *this;
		}

		std::map<value_type, int> get_frequencies()
		{
			std::map<value_type, int> freqs;
			
			for( int i = 0; i < length(); i++ )
			{
				int count = freqs.count( val_at(i) );
				std::cout << count << std::endl;
			}

			return freqs;
		}
		