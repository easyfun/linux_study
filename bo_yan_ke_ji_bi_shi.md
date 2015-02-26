2015年2月26日C/C++笔试总结<br/>

1.从一个字符串中查找一个子串<br/>
我的答题：
    // 缺少头文件包含
    int find_substr(const char *pszSrc, const char *pszSubstr)
    {
    	int nLenSrc=strlen(pszSrc);
    	int nLenSubstr=strlen(pszSubstr);
    
    	int nFindPos=-1;
    	char *pszTemp=new char[nLenSubstr+1];// 问题new的内存后边没有清理
    	pszTemp[nLenSubstr]=0;
    	for (int i=0;i<nLenSrc;i++)
    	{
		    memcpy(pszTemp,pszSrc+i,nLenSubstr);//没有判断源字符串与子字符串的长度大小，越界访问
    		if (0==strcmp(pszTemp,pszSubstr))
	    	{
    			nFindPos=i;
	    		break;
		    }
    	}
    
    	return nFindPos;
    }

修正<br/>
解法1<br/>
    #include <string.h>
    int find_substr(const char *pszSrc, const char *pszSubstr)
    {
    	int nLenSrc=strlen(pszSrc);
    	int nLenSubstr=strlen(pszSubstr);
    
	    if (nLenSubstr > nLenSrc)
    		return -1;
    
	    int nFindPos=-1;
    	char *pszTemp=new char[nLenSubstr+1];
	    pszTemp[nLenSubstr]=0;
    	for (int i=0;i<nLenSrc;i++)
	    {
    		memcpy(pszTemp,pszSrc+i,nLenSubstr);
    		if (0==strcmp(pszTemp,pszSubstr))
    		{
	    		nFindPos=i;
		    	break;
    		}
    
	    	if (nLenSrc-i == nLenSubstr)
		        break;
    	}

    	delete[] pszTemp;
    	pszTemp=NULL;
	    return nFindPos;
    }

解法2<br/>
	#include <string>
	using namespace std;

    int find_substr(const char *pszSrc, const char *pszSubstr)
    {
		std::string str_src=pszSrc;
		return str_src.find(pszSubstr);
	}


2.合并两个单向递增链表<br/>
借助std::list<br/>
用C实现链表，比较繁琐<br/>