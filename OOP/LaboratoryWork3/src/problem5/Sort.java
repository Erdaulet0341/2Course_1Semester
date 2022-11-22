package problem5;


public class Sort {
		
	static <E extends Comparable<E>> void BubbleSort(E [] arr) {
		for (int j = arr.length - 1; j >= 0; j--) {
	        for (int i = 1; i <= j; i++) {
	            if (arr[i-1].compareTo(arr[i]) > 0) {
	                E temp = arr[i-1];
	        		arr[i-1] = arr[i];
	        		arr[i] = temp;
	            }
	        }
	    }
	}
	
	static <E> void swap(E[] arr, int i, int j) {
		E tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	
	public static <E extends Comparable<E>> void quicksort(E[] arr, int a, int b) {
		if (a < b) {
			E x = arr[(a + b) / 2];
	
			do{
				while (arr[a].compareTo(x) < 0) a++;
				while (x.compareTo(arr[b]) < 0) b--;
		
				if ( a <= b) {
					swap(arr, a, b);
					a++;
					b--;
				}
	
			}
			while (a <= b);
				quicksort(arr, a, b);
				quicksort(arr, a, b);
		}
	}
}
