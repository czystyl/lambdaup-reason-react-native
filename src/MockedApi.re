type person = {
  firstName: string,
  lastName: string,
  id: int,
  photo: string,
};

type response =
  | Response(int, list(person))
  | Error(int, string);

let data = [
  {firstName: "Jakub", lastName: "Klobus", id: 0, photo: ""},
  {firstName: "Matt", lastName: "Zatorski", id: 1, photo: ""},
  {firstName: "Luke", lastName: "Czyszczonik", id: 2, photo: ""},
  {firstName: "Adam", lastName: "Malysz", id: 3, photo: ""},
  {firstName: "Lambd", lastName: "Up", id: 4, photo: ""},
  {firstName: "Mike", lastName: "Grabowski", id: 5, photo: ""},
];

let getData = () => {
  Random.self_init();
  let randomValue = Random.int(4);
  switch (randomValue) {
  | 0 => Error(404, "Cannot find data")
  | 1 => Response(200, [])
  | _ => Response(200, data)
  };
};