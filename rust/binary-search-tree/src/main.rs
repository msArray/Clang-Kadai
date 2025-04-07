#[derive(Debug, PartialEq, Eq)]
pub struct BinarySearchTree<T: Ord> {
    BinarySearchTreeInner<T>,
}

#[derive(Debug, PartialEq, Eq)]
enum BinarySearchTreeInner<T: Ord> {
    Nil,
    Node {
        val: T,
        left: Box<Self>,
        right: Box<Self>,
    },
}

impl<T: Ord> BinarySearchTree<T> {
    pub fn new() -> Self {
        Self(BinarySearchTreeInner::Nil)
    }

    pub fn add(&mut self, val: T) {
        let nil = Self::find_nil_to_add(&mut self.0, &val);

        *nil = BinarySearchTreeInner::Node{
            val,
            left: Box::new(BinarySearchTreeInner::Nil),
            right: Box::new(BinarySearchTreeInner::Nil),
        }
    }

    fn find_nil_to_add<'t, 'v>(
        cur_node: &'t mut BinarySearchTreeInner<T>,
        val: &'v T,
    ) -> &'t mut BinarySearchTreeInner<T> {
        match cur_node {
            BinarySearchTreeInner::Nil => cur_node,

            BinarySearchTreeInner::Node {
                val: cur_v,
                left,
                right,
            } => {
                if val <= cur_v {
                    Self::find_nil_to_add(left, &val)
                } else {
                    Self::find_nil_to_add(right, &val)
                }
            }
        }
    }
}

#[test]
fn add_in_same_order() {
    use BinarySearchTree;

    let mut bst1 = BinarySearchTree::new();
    bst1.add(1);
    bst1.add(2);

    let mut bst2 = BinarySearchTree::new();
    bst2.add(1);
    bst2.add(2);

    assert_eq!(bst1, bst2);
}

#[test]
fn add_in_different_order1() {
    use BinarySearchTree;

    let mut bst1 = BinarySearchTree::new();
    bst1.add(1);
    bst1.add(2);

    let mut bst2 = BinarySearchTree::new();
    bst2.add(2);
    bst2.add(1);

    assert_ne!(bst1, bst2);
}

#[test]
fn add_in_different_order2() {
    use BinarySearchTree;

    let mut bst1 = BinarySearchTree::new();
    bst1.add(8);
    bst1.add(5);
    bst1.add(10);
    bst1.add(5);
    bst1.add(3);
    bst1.add(5);
    bst1.add(6);
    bst1.add(8);
    bst1.add(9);
    bst1.add(15);

    let mut bst2 = BinarySearchTree::new();
    bst2.add(8);
    bst2.add(10);
    bst2.add(5);
    bst2.add(15);
    bst2.add(9);
    bst2.add(6);
    bst2.add(5);
    bst2.add(8);
    bst2.add(3);
    bst2.add(5);

    assert_eq!(bst1, bst2);
}

fn main() {
    println!("Hello, world!");
}
