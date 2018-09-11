type person = {
  firstName: string,
  lastName: string,
};

type response =
  | Response(int, list(person))
  | Error(int, string);

let data = [
  {firstName: "Jakub", lastName: "Klobus"},
  {firstName: "Matt", lastName: "Zatorski"},
  {firstName: "Luke", lastName: "Czyszczonik"},
  {firstName: "Adam", lastName: "Malysz"},
  {firstName: "Lambd", lastName: "Up"},
  {firstName: "Mike", lastName: "Grabowski"},
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