import Pygame
import pygame.gfxdraw

class Circular_linked_list(list):
	def swap_top(self):
		a = self.pop()
		b = self.pop()
		self.append(a)
		self.append(b)
	
	def rotate(self):
		a = self.pop()
		self.insert(0, a)
	
	def reverse_rotate(self):
		a = self.pop(0)
		self.append(a)

class UnknownOp(Exception):	pass

class Two_stacks:
	def __init__(self, list, verbose=False):
		self.a = Circular_linked_list(list)
		self.b = Circular_linked_list()
		if verbose:
			print("Initial state: %s" % str(self))
	
	def __str__(self):
		return "A = %s, B = %s" % (str(self.a), str(self.b))
	
	def do_op(self, op, verbose=False):
		if verbose:
			print("Applying %s: %s" % (op, str(self)))
		if op == "sa":
			self.a.swap_top()
		elif op == "sb":
			self.b.swap_top()
		elif op == "ss":
			self.a.swap_top()
			self.b.swap_top()
		elif op == "pa":
			self.a.append(self.b.pop())
		elif op == "pb":
			self.b.append(self.a.pop())
		elif op == "ra":
			self.a.rotate()
		elif op == "rb":	
			self.b.rotate()
		elif op == "rr":
			self.a.rotate()
			self.b.rotate()
		elif op == "rra":
			self.a.reverse_rotate()
		elif op == "rrb":
			self.b.reverse_rotate()
		elif op == "rrr":
			self.a.reverse_rotate()
			self.b.reverse_rotate()
		else:
			raise UnknownOp
	
	def is_sorted(self):
		if len(self.b) > 0:
			return False
		a = self.a
		for i, v in enumerate(a[:-1]):
			if a[i + 1] > v:
				return False
		return True

class Canvas:
	def __init__(self, width, height, title):
		pygame.init()
		self.screen = pygame.display.set_mode((width, height), pygame.HWSURFACE | pygame.DOUBLEBUF)
		self.width = width
		self.height = height
		self.clear()
	
	def clear(self):
		self.screen.fill((255, 255, 255))
	
	def conv_coord(self, x, y):
		new_x = int((x + .5) * self.width)
		new_y = int(y * self.width + self.height / 2)
		return new_x, new_y

	def line(self, x1, y1, x2, y2):
		p1 = self.conv_coord(x1, y1)
		p2 = self.conv_coord(x2, y2)
		pygame.draw.lines(self.screen, (0, 0, 0), False, [p1, p2], 1)
	
	def circle(self, x, y, r):
		r = int(r * self.width)
		if (r > 0):
			p = self.conv_coord(x, y)
			if (r <= 1):
				pygame.gfxdraw.pixel(self.screen, p[0], p[1], (1, 1, 1))
			else:
				pygame.gfxdraw.filled_circle(self.screen, p[0], p[1], r, (1, 1, 1))
				pygame.gfxdraw.aacircle(self.screen, p[0], p[1], r, (1, 1, 1))
	
	def show(self):
		pygame.display.update(self.screen.get_rect())

def repr_cll(cll):
	from math import pi, cos, sin
	perimeter = sum(cll) * 2.
	main_radius = perimeter / (2. * pi)
	main_circle = (0, 0, main_radius)
	circles = []
	s = 0.
	for i, n in enumerate(cll):
		s -= float(cll[i])
		angle = s * 2. * pi / perimeter
		x = main_radius * cos(angle)
		y = main_radius * sin(angle)
		radius = float(cll[i])
		circles.append((x, y, radius))
		s -= float(cll[i])
	return (main_circle, circles)

def draw_cll(canvas, cll_repr, xshift, xfact, fact):
	_, circles = cll_repr
	for circle in circles:
		x, y, radius = circle
		canvas.circle((x * xfact + xshift) * fact, y * fact, radius * fact)

def draw(canvas, ts):
	c1 = repr_cll(ts.a)
	c2 = repr_cll(ts.b)
	r1 = c1[0][2]
	r2 = c2[0][2]
	x1 = -r1 - .5
	x2 = -r2 - .5
	width = 2.2 * (r1 + r2)
	height = max(r1, r2) * 2.2
	h_fact = 1. / float(width)
	v_fact = (float(canvas.height) / float(canvas.width)) / height
	fact = min(h_fact, v_fact)
	canvas.clear()
	draw_cll(canvas, c1, -r2 * 1.1, 1., fact)
	draw_cll(canvas, c2, r1 * 1.1, -1., fact)
	canvas.show()

if __name__ == "__main__":
	from sys import argv, stdin, exit
	from time import sleep

	if len(argv) > 1 and argv[1] == "-v":
		verbose = True
		list_of_numbers = [int(i) for i in argv[:1:-1]]
	else:
		verbose = False
		list_of_numbers = [int(i) for i in argv[:0:-1]]
	i = list_of_numbers[::1]
	i.sort()
	list_of_numbers = [i.index(n) + 1 for n in list_of_numbers]
	ts = Two_stacks(list_of_numbers, verbose)
	canvas = Canvas(1920, 1080, 'push_swap checker')
	for op in stdin:
		for event in pygame.event.get():
			pass
		op = op.rstrip('\n')
		ts.do_op(op.rstrip('\n'), verbose)
		draw(canvas, ts)
	print("OK" if ts.is_sorted() else "KO")
	pygame.quit()
