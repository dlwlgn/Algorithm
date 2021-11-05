# 연결 요소의 개수

## 문제 링크
https://www.acmicpc.net/problem/11724

## 풀이 방법
DFS, 그래프

## 간단한 풀이 설명
인접 2차원 배열로 그래프를 만든다.<br>
1번 노드부터 N번 노드까지 for문을 돌리고 하나씩 DFS를 한다.<br>
만약 특정 노드가 시작부터 visited값이 true이면 DFS를 하지 않는다.<br>
DFS를 하며 방문한 노드는 visited에 true로 체크한다.<br>
for문에서 DFS에 한번 들어갈때마다 cnt값을 1씩 올려준다.<br>
cnt 값을 반환한다.<br>