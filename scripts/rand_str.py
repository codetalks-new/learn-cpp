import random
metas = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+-x/%*[]{}()?#!=^&@'

def rand_str(n:int):
  N = len(metas)
  if n < N:
    return metas[:n]
  m = n//N
  remain = n % N
  return metas *m + metas[:remain]

strs = []
for i in range(1,257):
  rs = rand_str(i)
  s = f'"{rs}"'
  strs.append(s)

print(',\n'.join(strs))
  