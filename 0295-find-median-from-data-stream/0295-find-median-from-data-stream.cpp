class MedianFinder {
public:
    multiset<int> Set1;
    multiset<int> Set2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(Set1.empty() || num <= *Set1.rbegin())
            Set1.insert(num);
        else
            Set2.insert(num);
        int len1 = Set1.size();
        int len2 = Set2.size();
        if(len1 - len2  > 1) {
            Set2.insert(*Set1.rbegin());
            Set1.erase(--Set1.end());
        }
        if(len2 - len1 > 0) {
            Set1.insert(*Set2.begin());
            Set2.erase(Set2.begin());
        }
    }
    
    double findMedian() {
        int len = Set1.size() + Set2.size();
        if(len % 2 == 1) 
            return *Set1.rbegin();
        else
            return (*Set1.rbegin() + *Set2.begin()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */