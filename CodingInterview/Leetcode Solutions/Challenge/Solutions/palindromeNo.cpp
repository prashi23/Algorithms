bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x!=0)){
            return false;
        }
        int rNo = 0;
        while(x > rNo){
           rNo = rNo * 10 + x % 10;
           x /= 10;
        }
        return x == rNo || x == rNo/10;
    }
