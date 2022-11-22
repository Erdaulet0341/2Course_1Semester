package problem3;


public interface Mycollection<E>{
	boolean add(E e);
	
	int size();
	
	void clear();
	
	boolean isEmpty();
	
	boolean remove();
	
	boolean contains();
}
