package problem3;

import java.util.Iterator;

public interface Mycollection<E>{
	boolean add(E e);
	
	int size();
	
	void clear();
	
	boolean isEmpty();
	
	boolean remove(E e);
	
	boolean contains(E e);
	
	public Iterator iterator();
}
