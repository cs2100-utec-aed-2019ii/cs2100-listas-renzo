template <typename T>
class abstraction_Iterator{
	public:
	typedef T node_t;
	typedef typename node_t::value_t value_t;

protected:
	node_t * pointer; 
public: 

	abstraction_Iterator(node_t* _pointer = nullptr):pointer(_pointer){
	}

	~abstraction_Iterator(void){
	}

	virtual bool operator!= (abstraction_Iterator it){
		return pointer != it.pointer;
	}

	virtual value_t& operator* (void) {
		return **pointer;
	}


/*	virtual abstraction_Iterator& operator++(void) const = 0;
	virtual abstraction_Iterator& operator++(int) const = 0;
	virtual abstraction_Iterator& operator--(void) const = 0;
	virtual abstraction_Iterator& operator--(int) const = 0;
*/	
/*	virtual bool operator == (const abstraction_Iterator&) const = 0;
	virtual bool operator != (const abstraction_Iterator&) const = 0;
	virtual bool operator <= (const abstraction_Iterator&) const = 0;
	virtual bool operator >= (const abstraction_Iterator&) const = 0;
	virtual bool operator < (const abstraction_Iterator&) const = 0;
	virtual bool operator > (const abstraction_Iterator&) const = 0;
	
	virtual void operator=(const V&) = 0;
*/

};
