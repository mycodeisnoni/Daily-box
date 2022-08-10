const arr = [1, "1", function test(){}]

console.log(arr[1])

```const zero = arr[0]
const one = arr[1]
const two = arr[2]

```
// 배열에서는 순서가 보장된다
// 따라서 임의의 변수를 등록해도 된다.
const [zero,one,two] = arr;