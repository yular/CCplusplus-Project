//Learned from Wikipedia. The Qsort without median-of-three optimization
struct Range{
	int start, end;
	Range(int s = 0, int e = 0): start(s), end(e) {}
};

void qsort(vector<int> arr){
	if(arr.size() <= 0)
		return ;
	stack<Range> st;
	st.push(Range(0,arr.size()-1);
	while(!st.empty()){
		Range range = st.top();
		st.pop();
		int pivot = arr[range.end];
		int pos = range.start - 1;
		for(int i = range.start; i < range.end; ++ i){
			if(arr[i] < pivot){
				swap(arr[i], arr[++ pos]);
			}
		}
		swap(arr[++ pos], arr[range.end]);
		if(pos-1 > range.start){
			st.push(Range(range.start, pos - 1));
		}
		if(pos+1 < range.end){
			st.push(Range(pos + 1, range.end));
		}
	}
}
