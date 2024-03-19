# 1.VCS란 무엇인가 #
    * 버전관리 시스템(VCS, Version Control System)이란 파일 변화를 시간에 따라 기록했다가 나중에 특정 시점의 버전을 다시 불러올 수 있는 시스템

#  2.DVCS와 VCS의 차이점 #
    * DVCS는각 개발자가 전체 저장소의 복사본을 가지고있으며 이를 통해 독립적으로 작업가능
    * vcs는 중앙서버에서 단일 복사본을 저장하고, 개발자들이 중앙서버파일을 가져와 작업후 변경사항을 단일서버에 반영함

# 3.깃 배쉬를 이용한 리포지스토리 연결법 #
    *  git init 내가 생성한 폴더를 깃에 등록하여 관리리 할수 있도록한다
    원격 저장소와 연결시키거나 초기화 시키는데 사용
    *  git add는 git에 명령어를 커밋할수 있는 상태로 만든다
    * git status는 변경된 사항이 있나 보여줌
    * git commit는 커밋이 가능한 파일들의 변경사항을 저장시킴
    * push는 저장된 파일을 저장소에 업로드함
    * remote는 init를통해 변환돈 파일을 깃허브에서 원격으로 관리 할수 있도록 연결 시켜줌

# irnore사용법과 작성 방법 #
    * ignore란 사용자가 등록되지 않길 원하는 파일이나 폴더의 목록을 정함
    * .md ;md확장자로 끝나는 모든 파일 제외
    * !;는 예외 사항 만들기
    * /build; 경로와 상관없이 build라는 이름의 디렉토리 및 그 안의 모든 파일들 제외
    * /build;현재 경로에 있는 build 디렉토리에 있는 모든 파일을 제외
    * build/ ; build라는 디렉토리 안에 있는 모든 파일 제외
    * build/ build라는 디렉토리 하위 파일들 중에서 txt 확장자로 끝나는 모든 파일 제외 build/*.txt
#build라는 디렉토리 하위 디렉토리들 안에 pdf 확장자 모두 제외
build/**/*

#  ReadMe.md 파일에 사용된 Mark Down 표기법에 대해
## 제목 (header 은 
### 샵의 갯수로 표현할수 있음 

1. 숫자와
2. 점을 이용하여 작성

-  하이픈, 아스테리스크 플러스사인을
-  사용하여 작성 tap나 스페이스바를 이용하여 들여쓰기 가능

* 하이픈, 아스테리스크, 플러스 사인을 3개이상 입력하면 수평션을 작성할수 있음
--------------
* 하이픈 아시테리스크 플러스 사인을 3개 이상 입력시 수편선 작성가능
``` 위 아래로 백틱을 세게 사용하여 작성
```

* 인라인링크 [111](https://www.google.co.kr/)
* url링크 <https://www.google.co.kr/>

* ![고양이사진](https://www.google.com/url?sa=i&url=https%3A%2F%2Fkr.freepik.com%2Fphotos%2F%25EA%25B0%2595%25EC%2595%2584%25EC%25A7%2580&psig=AOvVaw1LHKZaz9ICIOHCLmQHUhHx&ust=1710928077715000&source=images&cd=vfe&opi=89978449&ved=0CBEQjRxqFwoTCICcr_SFgIUDFQAAAAAdAAAAABAD)

* 강조는 *별 기호혹은 언더바 기호를 한번 사용* 혹은 __언더바 혹은 별기호를 두번 사용__  

    



