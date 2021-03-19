from absl import logging
from absl.testing import absltest


class TestStringMethods(absltest.TestCase):

  def test_upper(self):
    logging.info('NOW TESTING!')
    self.assertEqual('foo'.upper(), 'FOO')

  def test_isupper(self):
    self.assertTrue('FOO'.isupper())


if __name__ == '__main__':
  absltest.main()
