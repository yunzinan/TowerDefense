# TowerDenfense DevDoc

## TimeLine

- 阶段一: `地图创建`, `单位创建`, `交战机制`
- 阶段二: `地图导入/导出`, `词缀机制`
- 阶段三: `单位的动画特效(攻击和受伤效果)`
- 阶段四: `拓展`

---

## Game Settings

### Config

- `MAPMAXWIDTH`=20
- `MAPMAXHEIGHT`=10
- `GRIDWIDTH`=80
- `GRIDHEIGHT`=80


### Map

- size:
  - `mapWidth`=m, $10\le m\le 20$
  - `mapHeight`=n, $4\le n\le 10$

- `vector<path> pathList` 路径列表, 记录地图上的所有路径.

- `struct path` 路径, 一条路径对应一个起点和一个终点, 但是不同的路径的起点和终点可以重合.
  > 路径是怪物的行径路线, 每个怪物按照`路径id`进行运动, 
  - `startPoint` 起点坐标
  - `endPoint` 终点坐标
  - `vector<pair<int x, int y>> turingPointList` 拐点列表, 记录所有的关键节点: 路径拐弯的地方
  > [ex]`bool isSpecial` 特殊路径标识

### Enemy

- `enemyType` 词缀机制 
- `hp` 当前的血量
- `maxHp` 怪物最大的血量, 如果能够加血的话, 会有作用. 此外, 血条的设计也与此有关.
- `atk` 攻击力
- `atkRange` 攻击范围
- `atkSpeed` 攻击速度
- `moveSpeed` 移动速度
- `isMovable` 当前是否能够给移动的状态, 如果被阻塞(遇到近战塔), 则不能移动
- `posX, posY` 坐标
- `moveDirection` 移动的方向()
- `QPixmap/QMovie marchingAnimation` 敌人的行进动画
- `QMovie attackAnimation`  敌人的攻击动画
- `destroy()` 调用死亡动画, 触发析构函数
- `attack(Tower* t)` 系统告诉敌人该攻击谁, 因此怪物自身只需要判定能够实施攻击.
- `QPainterEvent` 绘制血条
- `move()` 更新坐标, 等于$isMovable \times moveSpeed\times moveDirection$
- `mousePressEvent()` 当点击敌人时, 会显示其攻击力, 攻击速度的信息.(***人物边框加粗标识被选中, 或者地上出现圆环表示被选中)
- `mouseReLeaseEvent()` 鼠标释放时恢复未被选中的状态.

#### 移动和攻击的机制

- 移动机制

人物在$80\times80$的格子上运动, 人物的贴图的右下角为其坐标, 人物的运动坐标总是沿着方格的下边线和右边线, 大体上的运动路线是自右至左, 自上至下. 

人物的移动实际上包括了坐标的更新和动画的播放, 其中, 当人物被阻拦时, 依然会播放动画, 但是不能更新坐标.

- 攻击机制

攻击机制涉及全局所有的敌人实例和所有的塔的实例. 因此我认为判定谁该攻击谁这件事情最好由上层的系统层来做, 决定好了该敌人应该攻击谁后, 该敌人只需要对某个确定的塔进行尝试攻击即可. 否则, 需要给予怪物全局视野, 来判定该攻击谁, 框架层次有点混乱.

**攻击范围**的判定: 计算欧式距离.

#### 词缀机制

[TODO]

### 素材图鉴

> 地图的素材风格: 卡通, 类似宝可梦地图风格, 非路径的`grid`渲染就选择草地, 存在路径的`grid`就选择石子路, 这样的拼接效果会比较好.
>
> 人物的移动GIF最好选择是上下跳动(波比), 这样的动画效果会比较自然.

前期不实现动画, 统一用圆形代表敌人, 用正方形代表塔.


### Tower

> Tower只是一个广义的概念, 只代表我方单位.

- *`enemyType` 词缀机制 
- `hp` 当前的血量
- `maxHp` 塔最大的血量, 如果能够加血的话, 会有作用. 此外, 血条的设计也与此有关.
- `atk` 攻击力
- `atkRange` 攻击范围
  > 近战塔的攻击范围为1, 只能攻击$3\times 3$十字范围内的敌人.
- `atkSpeed` 攻击速度
- `posX, posY` 坐标
- **`QMovie attackAnimation`  塔的攻击动画 
  > 近战塔的攻击动画就是自身的动画, 远程塔的攻击动画还包括子弹的飞行动画.
- **`destroy()` 调用被摧毁动画, 触发析构函数
- `attack(Enemy* e)` 系统告诉塔该攻击谁, 因此自身只需要判定能够实施攻击.
- `QPainterEvent` 绘制血条
- ** `mousePressEvent()` 当点击敌人时, 会显示其攻击力, 攻击速度的信息, 还会以圆圈形式显示攻击范围.(***圆形用动画显示, 50%透明度)
- **`mouseReLeaseEvent()` 鼠标释放时恢复未被选中的状态.

### System[Core]

> 负责整局游戏的维护. 包括怪物的生成, 塔的放置, 攻击判定