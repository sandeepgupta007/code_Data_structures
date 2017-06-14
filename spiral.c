/*This code is used for printing spiral matrix of any size
1 2 3
4 5 6
7 8 9

then output : 1 2 3 6 9 8 7 4 5

*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int r1 = A.size()-1;
	int r0 = 0;
	int c0 = 0;
	int c1 = A[0].size()-1;
	int i,j;
 	while(result.size() < A.size()*A[0].size()){
 	    for(i=c0;i<=c1;i++) result.push_back(A[r0][i]);
 	    if(result.size() >= A.size()*A[0].size()) break;
 	    r0++;
 	    for(i=r0;i<=r1;i++) result.push_back(A[i][c1]);
 	    c1--;
 	    if(result.size() >= A.size()*A[0].size()) break;
 	    for(i=c1;i>=c0;i--) result.push_back(A[r1][i]);
 	    r1--;
 	    if(result.size() >= A.size()*A[0].size()) break;
 	    for(i=r1;i>=r0;i--) result.push_back(A[i][c0]);
 	    c0++;
 	}
	return result;
}
