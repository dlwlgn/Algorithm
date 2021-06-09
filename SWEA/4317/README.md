# 칩 생산

## 문제 링크
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWL21nCaM8wDFAUE

## 풀이 방법
DFS

## 간단한 풀이 설명
2x2 칩셋의 왼쪽 위 칸이 되는 부분을 인덱스 기준으로 잡아 0,0부터 H-2, W-2 까지 DFS를 돌린다. <br>
DFS의 트리 자식 개수는 2개로, 현재 위치를 인덱스 기준으로 하는 2x2 칩셋을 놓을지 안놓을지로 나누어 완전 탐색을 실행한다. <br>
DFS 탐색을 하며 total 변수에 칩셋 개수를 갱신해주고 끝에 도달했을 때 total_max 변수를 갱신한다. <br>

## 실수했던 부분
DFS 내부의 2중 for문에서 r행 c열에서부터 시작하게 하려고 반복문의 시작을 각각 r, c로 했었다. <br>
그러나 2중 반복문을 진행하며 행이 넘어가게 되었을 때, 시작 열이 0이 아닌 c가 되는 문제점이 있었다. <br>

## 아쉬운 부분
DFS로 완전탐색을 하고 있지만, 백트래킹이 존재하지 않아 SWEA의 채점 시스템에서 시간초과가 나며 50문제 중 48문제만 채점이 된다. <br>
어디서 백트래킹을 시켜줄 수 있을지 추후에 깨달음을 얻는다면 추가 예정 <br>