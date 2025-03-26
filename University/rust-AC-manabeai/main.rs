#![allow(
    non_snake_case,
    unused_variables,
    unused_assignments,
    unused_mut,
    unused_imports,
    unused_macros,
    dead_code
)]
// use ac_library::*;
// use itertools::Itertools;
// use proconio::input;
use std::{cmp::max, cmp::min, collections::HashMap, collections::HashSet, io::{self, BufRead}, str::*};

fn main() {
    let mut v1 = String::new();
    io::stdin().read_line(&mut v1).unwrap();
    let v0: Vec<&str> = v1.trim().split(' ').collect();
    let v2 = v0.len();
    let n = v0[(0) as usize].parse::<i32>().unwrap();
    println!("{}", n+4);
}

#[macro_export]
macro_rules! printvec {
    (vec:expr) => {
        println!("{}", vec.iter().join(" "));
    };
}
