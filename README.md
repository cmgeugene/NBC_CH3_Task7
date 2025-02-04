## 내일배움캠프 Unreal 트랙 7번 과제

### 필수 기능
+ Pawn 클래스 생성 `(TaskNo7.cpp, BP_TaskNo7Character)`
  + Capsule Component(루트)에 Spring Arm Component, Camera Component, Skeletal Mesh Component 부착
  + Capsule Component 와 Skeletal Mesh Component의 `SetSimulatePhysics` 비활성화
+ Enhanced Input 매핑 & 바인딩
  + PlayerController 클래스를 생성해 이동 액션 할당
  + 이동/회전 로직 구현
    + 전후좌우 이동, 마우스로 회전 구현.
    + 각각의 이동함수에 `AddActorLocalOffset`으로 구현하였으나 도전기능을 구현하면서 `Tick`에서 사용자 입력 통합 관리로 변경함. (`AddActorWorldOffset`으로 변경)
### 도전 기능
+ 축 분할 액션 구현
  + 이동 - 전후(W,S) / 좌우(A,D) / 상하(Space, Left Shift)
  + 회전 - Pitch(마우스 Y) / Yaw(마우스 X) / Roll(Q, E)
+ Orientation 기반 이동 구현
  + 드론의 이동 방향에 따라 기울어짐을 구현하였음 예) 전후 이동시 pitch 증감, 좌우 이동시 roll 증감 
    + `Tick`에서 이동시 입력된 벡터에 따라 Skeletal Mesh의 pitch와 roll 결정
+ 인공 중력 구현
  + float `Gravity`와 FVector `ApplyGravity`를 이용, `Tick`에서 `AddActorWorldOffset`으로 중력을 적용
  + `GetActorLocation().Z` 로 착지 여부를 판단하고 착지시 중력 작용을 멈춤.

### 개인 구현 사항
+ 드론의 가속도 기반 이동
  + 회전이 아닌 이동의 경우 `InputAcceleration`으로 통합되며, InputAcceleration은 마찰력에 따라 서서히 감소함
+ 드론 애니메이션 설정
  + Fab을 통해 외부 에셋을 받음 (https://www.fab.com/listings/a9ab6351-7927-49bf-8c56-0c8449bbf1ca)
  + 동봉된 애니메이션은 `정지->프로펠러 가동->정지`여서 이를 `정지`, `프로펠러 가동`, `정지->가동` 으로 분리함
  + 2D Blendspace에서 액터의 Z 좌표 / 현재 가속도를 축으로 설정함(가속도가 0이어도 그 자리에서 호버링하는 경우 상정)
 
#### 진행 도중 겪었던 난관
+ 전진 키를 손에서 뗀 상태에서 탄력주행 중일때 카메라를 회전하면 카메라 방향으로 계속 진행 방향이 바뀌는 문제.
  + `AddActorLocalOffset`으로 전진하다보니 카메라 회전마다 전방이 바뀌면서 문제 발생. `AddActorWorldLocation`으로 바꿔서 월드 좌표 기준 X축으로 전진하도록 로직을 바꿈.
+ 마우스 XY 축으로 Pitch와 Yaw 적용시 각각 `AddActorLocalRotation`을 하다보니 회전축이 중첩되어 원하지 않는 roll이 발생함
  + 입력값을 각각 변수에 저장했다가 한 함수로 한번에 처리하도록 함. Yaw는 월드좌표 기반, Pitch는 로컬좌표 기반으로 변경하여 방지함.
