//
//  11679user.cpp
//  swea
//
//  Created by 임수정 on 2021/08/17.
//

#include <iostream>
using namespace std;


struct EventGrp{
    char name[15];
    int group;
};

char eventName[100][200][15];
int eventUid[100][200][5];
EventGrp userEvent[1000][100];

void mstrcpy(char dst[], const char src[]) {
    int c = 0;
    while ((dst[c] = src[c]) != 0) ++c;
}

int mstrcmp(const char str1[], const char str2[]) {
    int c = 0;
    while (str1[c] != 0 && str1[c] == str2[c]) ++c;
    return str1[c] - str2[c];
}

int eventNamePnts[100];
int eventUidPnts[100][200];
int userEventPnts[1000];

void init()
{
    for(int i = 0 ; i < 100 ; i++){
        eventNamePnts[i] = 0;
        for(int j = 0 ; j < 200 ; j++){
            eventUidPnts[i][j] = 0;
        }
    }
    
    for(int i = 0 ; i < 1000 ; i++){
        userEventPnts[i] = 0;
    }
}

void addEvent(int uid, char ename[], int groupid)
{
    //find in eventName
    bool isExist = false;
    for(int i = 0 ; i < eventNamePnts[groupid] ; i++){
        if(mstrcmp(eventName[groupid][i], ename) == 0){
            isExist = true;
            break;
        }
    }
    //save into eventName
    if(!isExist){
        mstrcpy(eventName[groupid][eventNamePnts[groupid]], ename);
    }
    
    //save into EventUid & UserEvent
    int currentUidIdx = eventUidPnts[groupid][eventNamePnts[groupid]];
    eventUid[groupid][eventNamePnts[groupid]][currentUidIdx] = uid;

    EventGrp eg;
    eg.group = groupid;
    mstrcpy(eg.name, ename);
    userEvent[uid][userEventPnts[uid]] = eg;
    
    cout << eventName[groupid][eventNamePnts[groupid]] << endl;
    cout << eventUid[groupid][eventNamePnts[groupid]][currentUidIdx] << endl;
    cout << userEvent[uid][userEventPnts[uid]].name << "," << userEvent[uid][userEventPnts[uid]].group << endl;
    
    userEventPnts[uid]++;
    eventNamePnts[groupid]++;
    eventUidPnts[groupid][eventNamePnts[groupid]]++;
    
}

int deleteEvent(int uid, char ename[])
{
    //find in userEvent
    bool isExist = false;
    int groupid = -1;
    for(int i = 0 ; i < userEventPnts[uid] ; i++){
        if(mstrcmp(userEvent[uid][i].name, ename) == 0){
            groupid = userEvent[uid][i].group;
            isExist = true;
            break;
        }
    }
    
    int cnt = 0;
    if(isExist){
        //find in eventName -> 그룹 내 이벤트 인덱스 찾기 (eventUidIdx)
        int eventUidIdx = -1;
        for(int i = 0 ; i < eventNamePnts[groupid] ; i++){
            if(mstrcmp(eventName[groupid][i], ename) == 0){
                eventUidIdx = i;
                break;
            }
        }
        
        //eventUid 에서 normal인지 master인지 확인
        if(eventUidIdx >= 0){
            bool isMaster = false;
            //max 5
            for(int i = 0 ; i < eventUidPnts[groupid][eventUidIdx] ; i++){
                if(eventUid[groupid][eventUidIdx][i] == uid){
                    if(i == 0){
                        //master
                        isMaster = true;
                        //userEvent에서 삭제
                        for(int j = 0 ; j < eventUidPnts[groupid][eventUidIdx] ; j++){
                            for(int k = 0 ; k < userEventPnts[eventUid[groupid][eventUidIdx][j]] ; k++){
                                if(mstrcmp(ename, userEvent[eventUid[groupid][eventUidIdx][j]][k].name) == 0 && userEvent[eventUid[groupid][eventUidIdx][j]][k].group == groupid){
                                    mstrcpy(userEvent[eventUid[groupid][eventUidIdx][j]][k].name, userEvent[eventUid[groupid][eventUidIdx][j]][userEventPnts[eventUid[groupid][eventUidIdx][j]]-1].name);
                                    userEvent[eventUid[groupid][eventUidIdx][j]][k].group =  userEvent[eventUid[groupid][eventUidIdx][j]][userEventPnts[eventUid[groupid][eventUidIdx][j]]-1].group;
                                    userEventPnts[eventUid[groupid][eventUidIdx][j]]--;
                                    cnt++;
                                }
                            }
                        }
                        //eventUid 맨뒤 원소 옮기기
                        for(int j = 0 ; j < eventUidPnts[groupid][eventNamePnts[groupid]-1] ; j++){
                            eventUid[groupid][eventUidIdx][j] = eventUid[groupid][eventNamePnts[groupid]-1][j];
                        }
                        //eventName 맨뒤 원소 옮기기
                        mstrcpy(eventName[groupid][eventUidIdx], eventName[groupid][eventNamePnts[groupid]-1]);
                        //
                        eventUidPnts[groupid][eventUidIdx] = eventUidPnts[groupid][eventNamePnts[groupid]-1];
                        eventUidPnts[groupid][eventNamePnts[groupid]-1] = 0;
                        eventNamePnts[groupid]--;
                        break;
                    }else{
                        //normal -> 삭제 (맨뒤 원소 옮기기)
                        eventUid[groupid][eventUidIdx][i] = eventUid[groupid][eventUidIdx][eventUidPnts[groupid][eventUidIdx]-1];
                        for(int i = 0 ; i < userEventPnts[uid] ; i++){
                            if(mstrcmp(userEvent[uid][i].name, ename) == 0){
                                mstrcpy(userEvent[uid][i].name, userEvent[uid][userEventPnts[uid]-1].name);
                                userEvent[uid][i].group = userEvent[uid][userEventPnts[uid]-1].group;
                                userEventPnts[uid]--;
                                cnt = 1;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
        return cnt;
    }else{
        return 0;
    }
    
    return 0;
}

int changeEvent(int uid, char ename[], char cname[])
{
    //find in userEvent
    bool isExist = false;
    int groupid = -1;
    for(int i = 0 ; i < userEventPnts[uid] ; i++){
        if(mstrcmp(userEvent[uid][i].name, ename) == 0){
            groupid = userEvent[uid][i].group;
            isExist = true;
            break;
        }
    }
    
    if(!isExist){
        return 0;
    }
    
    int eventUidIdx = -1;
    for(int i = 0 ; i < eventNamePnts[groupid] ; i++){
        if(mstrcmp(eventName[groupid][i], ename) == 0){
            eventUidIdx = i;
            break;
        }
    }
    
    int cnt = 0;
    if(eventUidIdx >= 0){
        bool isMaster = false;
        //max 5 -> master여부 확인
        for(int i = 0 ; i < eventUidPnts[groupid][eventUidIdx] ; i++){
            if(eventUid[groupid][eventUidIdx][i] == uid){
                if(i == 0){
                    //master
                    //eventName한번만 수정
                    for(int j = 0 ; j < eventNamePnts[groupid] ; j++){
                        if(mstrcmp(ename, eventName[groupid][j]) == 0){
                            mstrcpy(eventName[groupid][j], cname);
                        }
                    }
                    //userEvent 전체 수정
                    for(int k = 0 ; k < eventUidPnts[groupid][eventUidIdx] ; k++){
                        int uidIdx = eventUid[groupid][eventUidIdx][k];
                        for(int l = 0 ; l < userEventPnts[uidIdx] ; l++){
                            if(mstrcmp(userEvent[uidIdx][l].name, ename) == 0){
                                mstrcpy(userEvent[uidIdx][l].name, cname);
                                cnt++;
                            }
                        }
                        
                    }
                    break;
                }else{
                    //delete
                    deleteEvent(uid, ename);
                    //add
                    addEvent(uid, cname, groupid);
                    cnt = 1;
                }
            }
        }
    }
    
    return cnt;
}

int getCount(int uid)
{
    return userEventPnts[uid];
}

