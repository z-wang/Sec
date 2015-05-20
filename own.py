import gdb
import re

class MatPrinter:
    "Print mat"

    class _iterator:
        def __init__(self, start, n, m):
            self.item = start
            self.n = n
            self.m = m
            self.ncount = self.mcount = 0
            self.lead = '\n'
        def __iter__(self):
            return self
        def next(self):
            if self.ncount == self.n: raise StopIteration
            mcount = self.mcount
            ncount = self.ncount
            lead = self.lead
            self.lead = post = ''
            self.mcount = self.mcount + 1
            if self.mcount == self.m:
                self.mcount = 0
                self.ncount = self.ncount + 1
                if self.ncount == self.n:
                    post = '\n'
                self.lead = '\n'
            elt = self.item[ncount][mcount]
            return ('[%d,%d]' % (ncount, mcount), '%s%10s%s' % (lead, elt, post))

    def __init__(self, typename, val, n, m):
        self.typename = typename
        self.val = val
        self.n = n
        self.m = m
    def children (self):
        return self._iterator(self.val['v'], self.n, self.m)
    def to_string(self):
        return ('%s of dimension %dx%d' % (self.typename, self.n, self.m))
    def display_hint(self):
        return 'array'

def pp_lookup(val):
    lookup_tag = val.type.tag
    if lookup_tag == None:
        return None
    regex = re.compile('^mat<.*, *([0-9]*), *([0-9]*)>$')
    m = regex.match(lookup_tag)
    if m != None:
        return MatPrinter(lookup_tag, val, int(m.group(1)), int(m.group(2)))
    return None

gdb.pretty_printers.append(pp_lookup)
