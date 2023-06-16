
//* Time Complexity: O(n+m) Space Complexity: O(1)
// double merge(vector<int>& a, vector<int>& b,int mid,bool evenOdd){
// 	int first = 0, second = 0;
// 	int n = a.size()-1, m = b.size()-1;
// 	int count = 0, prevMidEle = 0, MidEle = 0;
// 	while(count<=mid && first<=n && second<=m){

// 		if(a[first]<b[second]){
// 			if(count==mid-1){
// 				prevMidEle = a[first];
// 			}
// 			MidEle = a[first++];
// 		}else{
// 			if(count==mid-1){
// 				prevMidEle = b[second];
// 			}
// 			MidEle = b[second++];
// 		}
// 		count++;
// 	}
// 	while(count<=mid && first<=n){
// 		if(count==mid-1){
// 			prevMidEle = a[first];
// 		}
// 		MidEle = a[first++];
// 		count++;
// 	}
// 	while(count<=mid && second<=m){
// 		if (count == mid - 1) {
// 			prevMidEle = b[second];
// 		}
// 		MidEle = b[second++];
// 		count++;
//     }
// 	if(evenOdd){
// 		return 1.0*MidEle;
// 	}else{
// 		double mead = 1.0*(MidEle + prevMidEle)/2.0;
// 		return mead;
// 	}
// }

// double median(vector<int>& a, vector<int>& b){
// 	// Write your code here.
// 	int n = a.size(), m = b.size();
// 	int total = n+m;
// 	if(total%2)
// 		return merge(a,b,total/2,true);
// 	return merge(a,b,total/2,false);
// }

//* Optimised Approach
// Time Complexity: O(min(logn, logm)) Space Complexity: O(1)
double median(vector<int> &a, vector<int> &b)
{
    // Write your code here.
    int n = a.size(), m = b.size();
    if (m < n)
    {
        swap(a, b);
        swap(n, m);
    }
    // return n;
    int start = 0, end = n, total = n + m;
    while (start <= end)
    {
        int part1 = start + (end - start) / 2;
        int part2 = (total + 1) / 2 - part1;
        int left1 = part1 == 0 ? INT_MIN : a[part1 - 1];
        int left2 = part2 == 0 ? INT_MIN : b[part2 - 1];
        int right1 = part1 == n ? INT_MAX : a[part1];
        int right2 = part2 == m ? INT_MAX : b[part2];

        if (left1 <= right2 && left2 <= right1)
        {
            if (total & 1)
                return 1.0 * max(left1, left2);
            double med = (max(left1, left2) + min(right1, right2)) / 2.0;
            return med;
        }
        else if (left1 > right2)
        {
            end = part1 - 1;
        }
        else
        {
            start = part1 + 1;
        }
    }
    return 0;
}