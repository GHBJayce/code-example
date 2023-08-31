package main

import (
    "fmt"
    "local_import_1/adir"
    "local_import_1/adir/bdir"
)

func main() {
    fmt.Println(adir.A(), adir.B())
    fmt.Println(bdir.A(), bdir.C())
}
