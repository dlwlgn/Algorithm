# 좌표 정렬하기2

## 문제 링크
https://www.acmicpc.net/problem/11651

## 풀이 방법
sort, compare function

## 간단한 풀이 설명
좌표들을 입력받는다<br>
y 좌표를 기준으로 정렬하고 같으면 x 좌표 기준으로 정렬하도록 compare 함수를 작성한다<br>


## 실수했던 부분
return에 <=를 쓰면 안된다. (strict weak ordering rule) <br>
