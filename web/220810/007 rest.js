const chicken = {
    type : "양념",
    drumsticks : 2,
    wing :2
}

```// const type = chicken.type
const {type} = chicken;

//type은 궁금한데 나머지는 객체로 갖고싶다면?
// rest문법 사용!```
const {type, ...another} = chicken;