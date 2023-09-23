## Modeless Dialog 
### 개발환경 : Visual Studio 2022
### 개발 과정
* Visual Studio 2022 새프로젝트-MFC-대화상자기반

![image](https://github.com/gryrryfh/visual-programming/assets/50912987/3c02b400-4058-44b0-8f2a-51ba5ea0dac0)  
  
* Dialog에 ListBox와 Button을 생성
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/f91bec56-4ea9-4f54-af35-4f661b0d6a6f)  
  
* ListBox 변수추가-범주 컨트롤, m-List이름으로 변경
  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/633587ea-fe90-44b8-b9f3-b44fbf136c12)  
  
* 이때 생성한 Button을 누르면 새 Dialog가 열리게 리소스뷰-Dialog-리소스 삽입
    
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ed52ece1-3539-4e6a-a95a-349f025cf6bb)  
  
* 생성된 Dialog에 Edit Control, Button 생성  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/97800ad1-4dda-46d8-be58-01c0bd2c3565)  
* Edit Control 변수추가-범주 값, m-String이름으로 변경  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0470c8d9-2081-4386-b527-75831cca5051)  
* 새로 생성된 Dialog에 클래스추가-CModeless로 생성  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/37c4e844-9f35-474d-a520-518ddb670822)  
* 부모 창 cpp파일에 Modeless 형태로 코딩  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/0666cc4b-2741-43a7-834c-96486ddef7c6)  
* CModeless클래스에 클래스마법사-가상함수 PostNcDestroy와 속성뷰의 메시지- WM_Close를 추가  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/ff1f579b-dbaf-4967-90f5-82f0a6bd1e1c)  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/13976f66-a565-4138-9f0c-0f545ff79dce)  
* CModeless에서 Button을 누르면 부모 ListBox에 나타나도록 코딩  
![image](https://github.com/gryrryfh/visual-programming/assets/50912987/4649e158-54c3-4ab1-8faf-ce30a42cef35)  
