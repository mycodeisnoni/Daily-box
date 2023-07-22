//prompt : 문자열을 입력받는 수단 중 1개

const result = prompt("세 문자열 입력");
console.log(result);

// 문자열 -> 배열
// split " "을 기반으로 나누기

const splitResult = result.split(" ");
console.log(splitResult);

const array = [];

for(let i =0;i<splitResult.length;i++){
    array.push(splitResult[i])
}