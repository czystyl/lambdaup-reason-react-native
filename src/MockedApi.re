type person = {
  firstName: string,
  lastName: string,
  id: int,
};

type response =
  | Response(int, list(person))
  | Error(int, string);

let data = [
  {firstName: "Jakub", lastName: "Klobus", id: 0},
  {firstName: "Matt", lastName: "Zatorski", id: 1},
  {firstName: "Luke", lastName: "Czyszczonik", id: 2},
  {firstName: "Adam", lastName: "Malysz", id: 3},
  {firstName: "Lambd", lastName: "Up", id: 4},
  {firstName: "Mike", lastName: "Grabowski", id: 5},
];

let getData = () => {
  Random.self_init();
  let randomValue = Random.int(4);
  switch (randomValue) {
  | 0 => Error(404, "Cannot find data")
  | 1 => Response(202, data)
  | _ => Response(200, data)
  };
};