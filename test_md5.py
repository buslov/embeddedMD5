import hashlib
import subprocess
import unittest



def md5emb(data):
    p = subprocess.run(["Debug/md5emb.exe"], input=data, capture_output=True, text=False)
    return p.stdout.strip().decode('ascii')



class Test(unittest.TestCase):
    def test_empty(self):
        data = b''
        h = hashlib.md5()
        h.update(data)
        self.assertEqual(h.hexdigest(), md5emb(data))

    def test_0123456789(self):
        data = b'0123456789'
        h = hashlib.md5()
        h.update(data)
        self.assertEqual(h.hexdigest(), md5emb(data))

    def test_long_data(self):
        data = bytes(range(255)) * 1000
        h = hashlib.md5()
        h.update(data)
        self.assertEqual(h.hexdigest(), md5emb(data))

    def test_0_255(self):
        data = bytes(range(256))
        h = hashlib.md5()
        h.update(data)
        self.assertEqual(h.hexdigest(), md5emb(data))


if __name__ == '__main__':
    unittest.main()
