package Go

type Pair struct {
	key   int
	value string
	next  *Pair
}

type Dict struct {
	init *Pair
}

func newDict() *Dict {
	return &Dict{init: nil}
}

func (d *Dict) search(key int) (bool, string) {
	cursor := d.init
	for cursor != nil {
		if cursor.key == key {
			return true, cursor.value
		}
		cursor = cursor.next
	}
	return false, "Key not found"
}

func (d *Dict) insert(key int, value string) {
	d.init = &Pair{key: key, value: value}
}

func (d *Dict) insertNew(key int, value string) {
	found, _ := d.search(key)
	if !found {
		d.insert(key, value)
	}
}

func (d *Dict) remove(key int) {
	cursor := d.init

	if d.init == nil {
		return
	}
	if d.init.key == key {
		d.init = d.init.next
		return
	}
	for cursor.next != nil {
		if cursor.next.key == key {
			cursor.next = cursor.next.next
			return
		}
		cursor = cursor.next
	}
}

func (d *Dict) destroyDict() {
	d.init = nil
}
