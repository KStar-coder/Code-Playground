# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import tensorflow as tf
tensor1 = tf.one([1,2,3])
tensor2 = tf.reshape(tensor1,[2,3,1])
print(tensor1)
print(tensor2)

String = tf.constant("Kaustav",tf.string)
print(String)