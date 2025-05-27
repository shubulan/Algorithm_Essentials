use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).unwrap();
    input.make_ascii_uppercase();
    println!("{}", input);
}