#include<stdio.h>
#include<iostream>
#include<sys/time.h>
using namespace std;

#include<ext/hash_map>
using namespace __gnu_cxx;

struct AuthData
{
    unsigned long uid;
    unsigned long sysid;
    unsigned long devid;
    char sessionkey[1024];
    char seed[256];
};

#define NUM 100000
AuthData g_array[NUM];

#define CAL_NUM 1

AuthData* TestFind(unsigned long uid,unsigned long sysid,unsigned long devid)
{
    for (int i=0;i<NUM;i++)
    {
        if (g_array[i].uid==uid
           /* && g_array[i].sysid==sysid
            && g_array[i].devid==devid*/)
            return &g_array[i];
    }
    return 0;
}

void test_array()
{
    int i=0;
    
    for (i=0;i<NUM;i++)
    {
        g_array[i].uid=i;
        g_array[i].sysid=i;
        g_array[i].devid=i;
    }

    timeval start,end;
    gettimeofday(&start,0);
//    cout<<"start:tv_sec="<<start.tv_sec<<" tv_usec="<<start.tv_usec<<endl;
    for (int i=0;i<CAL_NUM;i++)
//        TestFind(0,0,0);
//        TestFind(NUM/2,NUM/2,NUM/2);
//        TestFind(NUM-1,NUM-1,NUM-1);
        TestFind(NUM,NUM,NUM);
    gettimeofday(&end,0);
//    cout<<"end:tv_sec="<<end.tv_sec<<" tv_usec="<<end.tv_usec<<endl;
    double de=end.tv_sec*1000000.0+end.tv_usec;
    double ds=start.tv_sec*1000000.0+start.tv_usec;
//    long le=de;
//    long ls=ds;
//    cout<<"le="<<le<<" ls="<<ls<<endl;
    printf("time=%.1f us de=%.1f ds=%.1f\n",de-ds,de,ds);
}

int main(int argc, char* argv[])
{
    timeval its,ite;
    gettimeofday(&its,0);
    hash_map<unsigned long,AuthData*> MapAuthData;
    for (int i=0+989898; i<NUM+989898; i++)
    {
        AuthData* data=new AuthData;
        data->uid=i;
        data->sysid=i;
        data->devid=i;
        MapAuthData[i]=data;
    }
    gettimeofday(&ite,0);
    double dits=its.tv_sec*1000000.0+its.tv_usec;
    double dite=ite.tv_sec*1000000.0+ite.tv_usec;
    printf("init time=%.1f\n",dite-dits);

    timeval start,end;
    gettimeofday(&start,0);
    for (int i=0;i<CAL_NUM;i++)
        MapAuthData.find(0);
//        MapAuthData.find(NUM/2);
//        MapAuthData.find(NUM-1);
//        MapAuthData.find(NUM);
    gettimeofday(&end,0);
    double de=end.tv_sec*1000000.0+end.tv_usec;
    double ds=start.tv_sec*1000000.0+start.tv_usec;
    printf("time=%.1f us de=%.1f ds=%.1f\n",de-ds,de,ds);
    return 0;
}
