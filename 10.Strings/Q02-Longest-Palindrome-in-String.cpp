string longestPalin (string s) {
      // code here
      int start=0, end=1;
      int low,high;
      for(int i=1;i<s.length();i++)
      {
          //even part
          low=i-1;
          high=i;

          while(low>=0 and high<s.length() and s[low]==s[high])
          {
              if(high-low+1>end)
              {
                  start = low;
                  end = high-low+1;
              }
              low--;
              high++;
          }

          //odd part
          low=i-1;
          high=i+1;

          while(low>=0 and high<s.length() and s[low]==s[high])
          {
              if(high-low+1>end)
              {
                  start = low;
                  end = high-low+1;
              }
              low--;
              high++;
          }
      }
      return s.substr(start, end);
  }
