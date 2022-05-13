// Javascript Array 특성을 알기 위한 테스트 코드

/**
 * 배열 선언 후 초기화 하는 대표적인 3가지 방법
 * (1) for문 | (2) .fill() 메서드 | (3) Array.from 매서드
 * https://stackoverflow.com/questions/1295584/most-efficient-way-to-create-a-zero-filled-javascript-array
 */
let len = 5;

// 1번 방법: for문
const a1 = new Array(len);
for (let i = 0; i < len; i ++) {
    a1[i] = 0;
}

// 2번 방법: Array.prototype.fill() 메서드
const a2 = new Array(len).fill(0);

// 3번 방법: Array.from 메서드
const a3 = Array.from(Array(len), () => 0);

console.log(a1);    // [0, 0, 0, 0, 0]
console.log(a2);    // [0, 0, 0, 0, 0]
console.log(a3);    // [0, 0, 0, 0, 0]


/**
 * javascript는 현재 Array 보다 큰 index를 접근할 경우 그냥 undefined를 반환하고,
 * 현재 영역에 벗어난 영역에 write할 때는 array의 크기를 벗어난 부분까지 확장하고 그 사이 공간은 empty item으로 채운다.
 * 만약 너무 큰 수가 index로 들어오면, object 형태로 해당 index는 key 값이 됨.
 * 
 * 추측인데, read의 경우 property로 바로 알 수 있는 length 값보다 큰 값이 index에 들어오면 undefined를 리턴하도록 하고
 * write의 경우, length보다 큰 값이 index에 들어오면 배열을 새로 할당하고 copy한 다음 기존의 배열을 free하는 방식으로 
 * 내부적으로 구현했을 것으로 생각함.
 */
let arr = new Array(3).fill(0);
arr[10] = 1;
arr[100] = 2;
arr[1e+5] = 3;
arr[1e+10] = 4;

console.log(arr);
console.log(arr[1e+6]);
console.log(arr.length);

/**
 * 콘솔 출력 결과
    [
        0,
        0,
        0,
        <7 empty items>,
        1,
        <89 empty items>,
        2,
        <99899 empty items>,
        3,
        '10000000000': 4
    ]
    undefined
    100000001
 */
