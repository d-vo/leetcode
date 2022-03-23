class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int length = nums1.size() + nums2.size();
        std::vector<int> merged(length);
        int i = 0;
        int j = 0;

        int count = 0;
        while (count < length) {
            if (i == nums1.size()) {
                for (; j < nums2.size(); j++) {
                    merged[count] = nums2[j];
                    count++;
                }
            } else if (j == nums2.size()) {
                for (; i < nums1.size(); i++) {
                    merged[count] = nums1[i];
                    count++;
                }
            }

            if (count == length) {
                break;
            }

            if (nums1[i] < nums2[j]) {
                merged[count] = nums1[i];
                count++;
                i++;
            } else if (nums1[i] >= nums2[j]) {
                merged[count] = nums2[j];
                count++;
                j++;
            }
        }

        int half = (length - 1) / 2;
        if (length % 2 == 0) {
            return (merged[half] + merged[half + 1]) / 2.0;
        }

        return merged[half];
    }
};