package at.htlAnich;

public class AlgoExec {
	private AlgoExec(){}

	public static class Misc{

		public static int pow(int a, int b){
			int out = 0;
			for(int i = 0; i < b; ++i){
				out += a*b;
			}
			return out;
		}

		public static int faculty(int x){
			return x>1 ? x*faculty(x-1) : 1;
		}

		public static int sumFunction(int x){
			return x>=1 ? x+sumFunction(x-1) : 0;
		}

		public static class Count{
			public static int pow(int a, int b, Counter c){
				c.increaseWrites(2);
				int out = 0;
				c.increaseComparisons(1);
				for(int i = 0; i < b; ++i){
					c.increaseWrites(1);
					out += a*b;
					c.increaseComparisons(1);
				}
				return out;
			}

			public static int faculty(int x, Counter c){
				c.increaseComparisons();
				c.increaseRecursiveDepth();
				return (x>1) ? (x*faculty(x-1, c)) : 1;
			}
			public static int sumFunction(int x, Counter c){
				c.increaseComparisons();
				c.increaseRecursiveDepth();
				return (x>=1) ? (x+sumFunction(x-1, c)) : 0;
			}
		}
	}

	public static class Search{

		/** A recursive binary search on a sorted container.
		   @returns the index of the element. <code>-1</code> if it is not inside the container.
		 */
		public static int binaryRecur(MyArray arr, int searchFor, int lEnd, int rEnd){
			if(rEnd >= arr.length)
				return -1;

			if(lEnd <= rEnd){

				if(arr.get(lEnd) == searchFor)
					return lEnd;
				if(arr.get(rEnd) == searchFor)
					return rEnd;

				// adjust middle
				int middle = lEnd + ((rEnd - lEnd) / 2);
				if(arr.get(middle) == searchFor)
					return middle;

				if(searchFor < arr.get(middle))
					return binaryRecur(arr, searchFor, lEnd, middle);
				if(searchFor > arr.get(middle))
					return binaryRecur(arr, searchFor, middle, rEnd);
			}

			// Not found
			return -1;
		}

		/** A binary search on a sorted container.
		 @returns the index of the element. <code>-1</code> if it is not inside the container.
		 */
		public static int binary(MyArray arr, int searchFor){
			int left = 0;
			int right = arr.length-1;

			while(left <= right){
				if(arr.get(left) == searchFor)
					return left;

				if(arr.get(right) == searchFor)
					return right;

				// adjust middle
				int middle = left + ((right - left) / 2);
				if(arr.get(middle) == searchFor)
					return middle;

				if(searchFor < arr.get(middle))
					right = middle - 1;
				else
					left = middle + 1;
			}

			// Not found
			return -1;
		}

		/** A linear search on a container. Also works, if container is not sorted.
		 @returns the index of the element. <code>-1</code> if it is not inside the container.
		 */
		public static int linear(MyArray arr, int searchFor){
			for(int i = 0; i < arr.length; ++i){
				if(arr.get(i) == searchFor)
					return i;
			}
			// Not found
			return -1;
		}

		public static int doublyLinear(MyArray arr, int searchFor){

			// simple double sided sequentialSearch, just to make sure there is definitely the value inside
			int lowerIndex = 0;
			int upperIndex = arr.length-1;

			while(lowerIndex <= upperIndex){
				if(arr.get(lowerIndex) == searchFor){
					return lowerIndex;
				}
				if(arr.get(upperIndex) == searchFor){
					return upperIndex;
				}
				++lowerIndex;
				--upperIndex;
			}
			return -1;
		}

		public static int quadrupleLinear(MyArray arr, int searchFor){
			// one index starts from the lower end
			int llIndex = 0;
			// one index starts from the upper end
			int rrIndex = arr.length-1;
			// one index starts from the middle and goes downwards
			int mlIndex = arr.length/2;
			// one index starts from the middle and goes upwards
			int mrIndex = arr.length/2;

			while(llIndex <= mlIndex &&
					rrIndex >= mrIndex){
				if(arr.get(llIndex) == searchFor){
					return llIndex;
				}
				if(arr.get(rrIndex) == searchFor){
					return rrIndex;
				}
				if(arr.get(mlIndex) == searchFor){
					return mlIndex;
				}
				if(arr.get(mrIndex) == searchFor){
					return mrIndex;
				}

				++llIndex;
				--rrIndex;
				--mlIndex;
				++mrIndex;
			}

			return -1;
		}

		public static class Count{

			/** A recursive binary search on a sorted container.
			 @returns the index of the element. <code>-1</code> if it is not inside the container.
			*/
			public static int binary(MyArray arr, int searchFor, int lEnd, int rEnd, Counter c){
				c.increaseComparisons();
				if(rEnd >= arr.length())
					return -1;

				c.increaseComparisons();
				if(lEnd <= rEnd){

					c.increaseComparisons();
					if(arr.get(lEnd) == searchFor)
						return lEnd;

					c.increaseComparisons();
					if(arr.get(rEnd) == searchFor)
						return rEnd;


					// adjust middle
					c.increaseWrites();
					int middle = lEnd + ((rEnd - lEnd) / 2);
					c.increaseComparisons();
					if(arr.get(middle) == searchFor)
						return middle;

					c.increaseComparisons();
					if(searchFor < arr.get(middle)) {
						c.increaseRecursiveDepth();
						return binary(arr, searchFor, lEnd, middle, c);
					}
					c.increaseComparisons();
					if(searchFor > arr.get(middle)) {
						c.increaseRecursiveDepth();
						return binary(arr, searchFor, middle, rEnd, c);
					}
				}

				// Not found
				return -1;
			}

			/** A binary search on a sorted container.
			 @returns the index of the element. <code>-1</code> if it is not inside the container.
			 */
			public static int binary(MyArray arr, int searchFor, Counter c){

				c.increaseWrites(2);
				int	left = 0,
						right = arr.length()-1;

				c.increaseComparisons();
				while(left <= right){
					c.increaseComparisons();
					if(arr.get(left) == searchFor)
						return left;

					c.increaseComparisons();
					if(arr.get(right) == searchFor)
						return right;

					// adjust middle
					c.increaseWrites();
					int middle = left + ((right - left) / 2);
					c.increaseComparisons();
					if(arr.get(middle) == searchFor)
						return middle;

					c.increaseComparisons();
					c.increaseWrites();
					if(searchFor < arr.get(middle))
						right = middle - 1;
					else
						left = middle + 1;
					c.increaseComparisons();
				}

				// Not found
				return -1;
			}

			/** A linear search on a container. Also works, if container is not sorted.
			 @returns the index of the element. <code>-1</code> if it is not inside the container.
			*/
			public static int linear(MyArray arr, int searchFor, Counter c){
				c.increaseWrites();
				c.increaseComparisons();
				for(int i = 0; i < arr.length(); ++i){
					c.increaseWrites();

					c.increaseComparisons();
					if(arr.get(i) == searchFor)
						return i;

					c.increaseComparisons();
				}
				// Not found
				return -1;
			}

			public static int doublyLinear(MyArray arr, int searchFor, Counter c){

				// simple double sided sequentialSearch, just to make sure there is definitely the value inside
				c.increaseWrites(2);
				int lowerIndex = 0;
				int upperIndex = arr.length()-1;

				c.increaseComparisons();
				while(lowerIndex <= upperIndex){
					c.increaseComparisons();
					if(arr.get(lowerIndex) == searchFor){
						return lowerIndex;
					}
					c.increaseComparisons();
					if(arr.get(upperIndex) == searchFor){
						return upperIndex;
					}
					c.increaseWrites(2);
					++lowerIndex;
					--upperIndex;
					c.increaseComparisons();
				}
				return -1;
			}

			public static int quadrupleLinear(MyArray arr, int searchFor, Counter c){
				c.increaseWrites(4);

				// one index starts from the lower end
				int llIndex = 0;
				// one index starts from the upper end
				int rrIndex = arr.length()-1;
				// one index starts from the middle and goes downwards
				int mlIndex = arr.length()/2;
				// one index starts from the middle and goes upwards
				int mrIndex = arr.length()/2;

				c.increaseComparisons(2);
				while(llIndex <= mlIndex &&
						rrIndex >= mrIndex){
					c.increaseComparisons();
					if(arr.get(llIndex) == searchFor){
						return llIndex;
					}
					c.increaseComparisons();
					if(arr.get(rrIndex) == searchFor){
						return rrIndex;
					}
					c.increaseComparisons();
					if(arr.get(mlIndex) == searchFor){
						return mlIndex;
					}
					c.increaseComparisons();
					if(arr.get(mrIndex) == searchFor){
						return mrIndex;
					}

					c.increaseWrites(4);
					++llIndex;
					--rrIndex;
					--mlIndex;
					++mrIndex;
					c.increaseComparisons(2);
				}

				return -1;
			}
		}

	}

	public static class Sort{
		private Sort(){}

		public static void selectionStable(MyArray arr){
			for(var i = 0; i < arr.length(); ++i){

				var min = i;
				for(var j = i+1; j < arr.length(); ++j) {
					if(arr.get(min) > arr.get(j))
						min = j;
				}

				int key = arr.get(min);
				while(min > i){
					arr.set(min, arr.get(min-1));
					--min;
				}
				arr.set(i, key);
			}
			return;
		}

		public static void selection(MyArray arr){
			for(var i = 0; i < arr.length(); ++i){

				var min = i;
				for(var j = i+1; j < arr.length(); ++j){
					if(arr.get(min) > arr.get(j))
						min = j;
				}

				arr.swap(min, i);
			}
			return;
		}

		public static void bubble(MyArray arr){
			for(int i = 0; i < arr.length()-1; ++i){
				for(int j = 0; j < arr.length()-i-1; ++j){
					if(arr.get(j) > arr.get(j+1)){
						arr.swap(j, j+1);
					}
				}
			}
			return;
		}

		public static void insertion(MyArray arr){
			int	i,
					j,
					key;
			for(i = 1; i < arr.length(); ++i){
				key = arr.get(i);
				j = i-1;

				while(j >= 0 && arr.get(j) > key){
					arr.set(j+1, arr.get(j));
					--j;
				}
				arr.set(j+1, key);
			}
			return;
		}

		private static int quickPartition(MyArray arr, int l, int r) {
			var lIndex = l;
			var rIndex = r - 1;
			var pivot = arr.get(r);



			while (lIndex < rIndex) {

				while (lIndex < r && arr.get(lIndex) < pivot){
					++lIndex;


				}
				while (rIndex > l && arr.get(rIndex) >= pivot){
					--rIndex;


				}

				if (lIndex < rIndex){
					arr.swap(lIndex, rIndex);

				}

			}


			if (arr.get(lIndex) > pivot){
				arr.swap(lIndex, r);

			}
			return lIndex;
		}

		private static void quick(MyArray arr, int low, int high) {

			if(low >= high){
				return;
			}

			var pivot = quickPartition(arr, low, high);

			quick(arr, low, pivot - 1);

			quick(arr, pivot + 1, high);
		}

		public static void quick(MyArray arr){
			quick(arr, 0, arr.length()-1);
		}

		private static void mergeTogether(MyArray arr, int l, int middle, int r) {

			// copy lower half to new temporary array
			var lowerArrSize = middle - l + 1;
			var lowerArr = new MyArray(lowerArrSize);
			for (int i = 0; i < lowerArrSize; ++i) {
				lowerArr.set(i, arr.get(l + i));
			}

			// copy upper half to new temporary array
			var upperArrSize = r - middle;
			var upperArr = new MyArray(upperArrSize);
			for (int i = 0; i < upperArrSize; ++i) {
				upperArr.set(i, arr.get(middle + i + 1));
			}

			// create indices for merging
			int lowerArrayIndex = 0, upperArrayIndex = 0, resultsArrIndex = l;

			// merge all together
			//   lowerArrIndex can't be greater equals than underArrSize
			//   upperArrIndex can't be greater equals than upperArrSize
			//   resultsArrIndex can't be less than l
			//   resultsArrIndex can't be greater equals than r
			// if EITHER the upper array is done OR the lower array is done, then go for the next step where the
			// resuming parts of the counterpart is getting inserted
			while (lowerArrayIndex < lowerArrSize && upperArrayIndex < upperArrSize) {
				var lowerElement = (lowerArr.get(lowerArrayIndex)); // just for comparison!!!
				var upperElement = (upperArr.get(upperArrayIndex)); // just for comparison!!!

				if (lowerElement <= upperElement) {
					arr.set(resultsArrIndex++, lowerArr.get(lowerArrayIndex++));
				} else {
					arr.set(resultsArrIndex++, upperArr.get(upperArrayIndex++));
				}
			}

			// one temporary array was inserted completely, the other one has elements left in it
			// (even if it is only 1 element) just copy the resuming elements to the resulting

			// if lower array is done, then the upper can't be the same as the upperSize and therefore we
			// copy the resuming values from the upper one to the resulting
			// it won't execute the while, if the upper one is done and the lower is not
			while (upperArrayIndex < upperArrSize) {
				arr.set(resultsArrIndex++, upperArr.get(upperArrayIndex++));
			}

			// if upper array is done, then the lower can't be the same as the lowerSize and therefore we
			// copy the resuming values from the lower one to the resulting
			// it won't execute the while, if the lower one is done and the upper is not
			while (lowerArrayIndex < lowerArrSize) {
				arr.set(resultsArrIndex++, lowerArr.get(lowerArrayIndex++));
			}

			// everything is merged together as it should be
			// so let's clean up all the mess we made up before and then return out of here
			//delete lowerArr;
			//delete upperArr;
			// unfortunately we cannot delete the extra variables, because they are not pointers (yet, hehe)
			//delete middle;
			//delete lowerArrSize;
			//delete lowerArrIndex;
			//delete upperArrSize;
			//delete upperArrIndex;
			//delete resultsArrIndex;

			return;
		}

		private static void merge(MyArray arr, int l, int r) {
			if (l >= r || r >= arr.length()) {
				return;
			}

			// make the pivot element as the middle one
			var pivot = l + (r - l) / 2;

			// first mergeSort the lower half
			merge(arr, l, pivot);
			// second, mergeSort the upper half
			merge(arr, pivot + 1, r);
			// and finally merge lower and upper half together
			mergeTogether(arr, l, pivot, r);
		}

		public static void merge(MyArray arr) {
			merge(arr, 0, arr.length() - 1);
		}

		public static class Count{

			public static void selectionStable(MyArray arr, Counter c){
				c.increaseWrites();
				c.increaseComparisons();
				for(var i = 0; i < arr.length(); ++i){
					c.increaseWrites(2);
					var min = i;

					c.increaseWrites();
					c.increaseComparisons();
					for(var j = i+1; j < arr.length(); ++j) {
						c.increaseWrites();

						c.increaseComparisons();
						if(arr.get(min) > arr.get(j)) {
							c.increaseWrites();
							min = j;
						}
					}

					c.increaseWrites();
					int key = arr.get(min);

					c.increaseComparisons();
					while(min > i){

						c.increaseWrites(2);
						arr.set(min, arr.get(min-1));
						--min;

						c.increaseComparisons();
					}
					c.increaseWrites();
					arr.set(i, key);
				}
				return;
			}

			public static void selection(MyArray arr, Counter c){
				c.increaseWrites();
				c.increaseComparisons();
				for(var i = 0; i < arr.length(); ++i){
					c.increaseWrites(2);
					var min = i;

					c.increaseWrites();
					c.increaseComparisons();
					for(var j = i+1; j < arr.length(); ++j){
						c.increaseWrites();

						c.increaseComparisons();
						if(arr.get(min) > arr.get(j)) {
							c.increaseWrites();
							min = j;
						}
					}

					c.increaseWrites(3);
					arr.swap(min, i);
				}
				return;
			}

			public static void bubble(MyArray arr, Counter c){
				c.increaseWrites();
				c.increaseComparisons();
				for(int i = 0; i < arr.length()-1; ++i){
					c.increaseWrites();

					c.increaseWrites();
					c.increaseComparisons();
					for(int j = 0; j < arr.length()-i-1; ++j){
						c.increaseWrites();

						c.increaseComparisons();
						if(arr.get(j) > arr.get(j+1)){
							c.increaseWrites(3);
							arr.swap(j, j+1);
						}
					}
				}
				return;
			}

			public static void insertion(MyArray arr, Counter c){
				int	i,
						j,
						key;

				c.increaseWrites();
				c.increaseComparisons();
				for(i = 1; i < arr.length(); ++i){
					key = arr.get(i);
					j = i-1;
					c.increaseWrites(3);

					c.increaseComparisons(2);
					while(j >= 0 && arr.get(j) > key){

						c.increaseWrites(2);
						arr.set(j+1, arr.get(j));
						--j;

						c.increaseComparisons(2);
					}
					c.increaseWrites();
					arr.set(j+1, key);
				}
				return;
			}

			private static int quickPartition(MyArray arr, int l, int r, Counter c) {
				var lIndex = l;
				var rIndex = r - 1;
				var pivot = arr.get(r);
				c.increaseWrites(3);

				c.increaseComparisons();
				while (lIndex < rIndex) {
					c.increaseComparisons(2);
					while (lIndex < r && arr.get(lIndex) < pivot) {
						++lIndex;
						c.increaseComparisons(2);
						c.increaseWrites();
					}
					while (rIndex > l && arr.get(rIndex) >= pivot) {
						--rIndex;
						c.increaseComparisons(2);
						c.increaseWrites();
					}
					c.increaseComparisons();
					if (lIndex < rIndex) {
						arr.swap(lIndex, rIndex);
						c.increaseWrites(3);
					}
					c.increaseComparisons();
				}

				c.increaseComparisons();
				if (arr.get(lIndex) > pivot) {
					arr.swap(lIndex, r);
					c.increaseWrites(3);
				}
				return lIndex;
			}

			private static void quick(MyArray arr, int low, int high, Counter c) {
				c.increaseComparisons();
				if(low >= high){
					return;
				}

				var pivot = quickPartition(arr, low, high, c);
				c.increaseRecursiveDepth();
				quick(arr, low, pivot - 1, c);
				c.increaseRecursiveDepth();
				quick(arr, pivot + 1, high, c);
			}

			public static void quick(MyArray arr, Counter c){
				quick(arr, 0, arr.length()-1, c);
			}


			private static void mergeTogether(MyArray arr, int l, int middle, int r, Counter c) {

				// copy lower half to new temporary array
				c.increaseWrites(2); // assuming that a new "myArray" is only a pointer and therefore only 1 writeAccess
				var lowerArrSize = middle - l + 1;
				var lowerArr = new MyArray(lowerArrSize);
				for (int i = 0; i < lowerArrSize; ++i) {
					c.increaseWrites();
					lowerArr.set(i, arr.get(l + i));
				}

				// copy upper half to new temporary array
				c.increaseWrites(2); // assuming that a new "myArray" is only a pointer and therefore only 1 writeAccess
				var upperArrSize = r - middle;
				var upperArr = new MyArray(upperArrSize);
				for (int i = 0; i < upperArrSize; ++i) {
					c.increaseWrites();
					upperArr.set(i, arr.get(middle + i + 1));
				}

				// create indices for merging
				c.increaseWrites(3);
				int lowerArrIndex = 0, upperArrIndex = 0, resultsArrIndex = l;

				// merge all together
				//   lowerArrIndex can't be greater equals than underArrSize
				//   upperArrIndex can't be greater equals than upperArrSize
				//   resultsArrIndex can't be less than l
				//   resultsArrIndex can't be greater equals than r
				// if EITHER the upper array is done OR the lower array is done, then go for the next step where the
				// resuming parts of the counterpart is getting inserted
				c.increaseComparisons(2);
				while (lowerArrIndex < lowerArrSize && upperArrIndex < upperArrSize) {
					c.increaseWrites(2);
					var lowerElement = (lowerArr.get(lowerArrIndex)); // just for comparison!!!
					var upperElement = (upperArr.get(upperArrIndex)); // just for comparison!!!

					c.increaseComparisons();
					c.increaseWrites(3);
					if (lowerElement <= upperElement) {
						arr.set(resultsArrIndex++, lowerArr.get(lowerArrIndex++));
					} else {
						arr.set(resultsArrIndex++, upperArr.get(upperArrIndex++));
					}
					c.increaseComparisons(2);
				}

				// one temporary array was inserted completely, the other one has elements left in it
				// (even if it is only 1 element) just copy the resuming elements to the resulting

				// if lower array is done, then the upper can't be the same as the upperSize and therefore we
				// copy the resuming values from the upper one to the resulting
				// it won't execute the while, if the upper one is done and the lower is not
				c.increaseComparisons();
				while (upperArrIndex < upperArrSize) {
					c.increaseWrites(3);
					arr.set(resultsArrIndex++, upperArr.get(upperArrIndex++));
					c.increaseComparisons();
				}

				// if upper array is done, then the lower can't be the same as the lowerSize and therefore we
				// copy the resuming values from the lower one to the resulting
				// it won't execute the while, if the lower one is done and the upper is not
				c.increaseComparisons();
				while (lowerArrIndex < lowerArrSize) {
					c.increaseWrites(3);
					arr.set(resultsArrIndex++, lowerArr.get(lowerArrIndex++));
					c.increaseComparisons();
				}

				// everything is merged together as it should be
				// so let's clean up all the mess we made up before and then return out of here
				//delete lowerArr;
				//delete upperArr;
				// unfortunately we cannot delete the extra variables, because they are not pointers (yet, hehe)
				//delete middle;
				//delete lowerArrSize;
				//delete lowerArrIndex;
				//delete upperArrSize;
				//delete upperArrIndex;
				//delete resultsArrIndex;

				return;
			}

			private static void merge(MyArray arr, int l, int r, Counter c) {
				c.increaseComparisons(2);
				if (l >= r || r >= arr.length()) {
					return;
				}

				// make the pivot element as the middle one
				c.increaseWrites();
				var pivot = l + (r - l) / 2;

				// first mergeSort the lower half
				c.increaseRecursiveDepth();
				merge(arr, l, pivot, c);
				// second, mergeSort the upper half
				c.increaseRecursiveDepth();
				merge(arr, pivot + 1, r, c);
				// and finally merge lower and upper half together
				mergeTogether(arr, l, pivot, r, c);
			}

			public static void merge(MyArray arr, Counter c) {
				merge(arr, 0, arr.length() - 1, c);
			}
		}
	}
}
