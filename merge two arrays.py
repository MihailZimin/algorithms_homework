class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)

        if n1 > n2:
            return self.findMedianSortedArrays(nums2, nums1)

        n = n1 + n2
        left = (n + 1) // 2
        l = -1
        r = n1 + 1

        while r - l > 1:
            mid1 = (l + r) // 2
            mid2 = left - mid1

            l1 = -10**9
            l2 = -10**9
            r1 = 10**9
            r2 = 10**9

            if mid1 < n1:
                r1 = nums1[mid1]
            if mid2 < n2:
                r2 = nums2[mid2]
            if mid1 - 1 >= 0:
                l1 = nums1[mid1 - 1]
            if mid2 - 1 >= 0:
                l2 = nums2[mid2 - 1]


            if l1 <= r2 and l2 <= r1:
                if n % 2 == 1:
                    return max(l1, l2)

                else:
                    return (max(l1, l2) + min(r1, r2))  / 2.0

            elif l1 > r2:
                r = mid1
            else:
                l = mid1
        return 0
