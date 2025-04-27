#cc 5
#Implement network virtualization using VirtualBox

# **1. Install VirtualBox**
1. Go to the official site: [https://www.virtualbox.org/](https://www.virtualbox.org/).
2. Click on **Downloads**.
3. Download **Windows Hosts** if you are on Windows (or Mac/Linux accordingly).
4. Open the installer (.exe) → Click **Next** multiple times → **Install**.
5. Allow network permissions if Windows Firewall asks.
6. After installation, **open VirtualBox**.
7. **(Optional but recommended)**: Download and install the **Extension Pack** from the same website (it gives USB support, etc.).

✅ **VirtualBox is ready!**

---

# **2. Download an Operating System ISO**
You need an OS to install in your virtual machines.

Options:
- **Ubuntu Server** (lightweight Linux) → [https://ubuntu.com/download/server](https://ubuntu.com/download/server)
- **Alpine Linux** (very lightweight) → [https://alpinelinux.org/downloads/](https://alpinelinux.org/downloads/)
- **Windows 10/11 ISO** → [https://www.microsoft.com/en-us/software-download/](https://www.microsoft.com/en-us/software-download/)

✅ Save the downloaded `.iso` file in a folder.

---

# **3. Create Virtual Machines (VM1, VM2)**

**For each VM:**

### 3.1 Create New VM
- Open **VirtualBox** → Click the **New** button.
- Enter the name: **VM1** (example).
- Type: Choose **Linux** (or **Windows** if you downloaded Windows ISO).
- Version: (Example: Ubuntu 64-bit).

Click **Next**.

---

### 3.2 Allocate Memory
- Set **Memory Size**:
  - Minimum 1024 MB (1 GB) for Linux.
  - 2048 MB (2 GB) or more for Windows.

Click **Next**.

---

### 3.3 Create a Virtual Hard Disk
- Select: **Create a virtual hard disk now**.
- Click **Create**.
- Choose **VDI (VirtualBox Disk Image)**.
- Storage on physical hard disk: **Dynamically allocated** (recommended).
- Size: Around **10 GB** for Linux, **20–30 GB** for Windows.

Click **Create**.

✅ Now the VM is created — but still empty.

---

# **4. Attach ISO to VM (for OS Installation)**

1. **Right-click** your VM → **Settings** → **Storage**.
2. Under **Controller: IDE**, click the empty CD/DVD icon.
3. On the right side, click **Choose a disk file...**.
4. Browse and select the ISO file you downloaded.

Click **OK**.

✅ Now your VM will boot using the ISO file.

---

# **5. Install the OS Inside VM**

- Start the VM → It will boot from the ISO.
- Follow normal OS installation steps:
  - For Ubuntu:
    - Language selection → Install Ubuntu Server → Set Username and Password → Partition Disk → Finish installation.
  - For Windows:
    - Select "Install Now" → Choose Edition → Set Username, Password, etc.

After installation:
- Shut down the VM.
- Go to **Settings → Storage** → Remove the ISO from the Optical Drive.

✅ VM is now installed with an OS and ready to use!

---

# **6. Set Up Virtual Networks**

Here we actually **virtualize the network**.

There are **two good ways** to set up network virtualization:

---

## 6A. Create **Internal Network** (Only VMs Talk to Each Other)

1. **Right-click** VM1 → **Settings** → **Network**.
2. **Adapter 1**:
   - Check **Enable Network Adapter**.
   - Attached to: **Internal Network**.
   - Name: **Net1** (or any name you like).
   
Click **OK**.

Repeat the exact same steps for **VM2** — attach it to **Internal Network → Net1**.

✅ Now VM1 and VM2 are virtually connected **inside a private isolated network**.

---

## 6B. (Optional) Create **Host-Only Network** (PC + VMs can talk)

1. In VirtualBox, **go to**:
   - **File → Host Network Manager**.
2. Click **Create**.
   - A network like **vboxnet0** will be created.
   - (It will automatically assign IP addresses like 192.168.56.1).
3. Apply it to VMs:
   - Settings → Network → Attached to: **Host-Only Adapter**.
   - Name: **vboxnet0**.

✅ Now your Host Machine (PC) and VMs are on the same network!

---

# **7. Start VMs and Check Networking**

1. Start both VM1 and VM2.
2. Login to both VMs.

On Linux, open terminal and check IP address:
```bash
ip addr

or
```bash
ifconfig

On Windows, open command prompt:
```bash
ipconfig


✅ You should see IP addresses like:
- VM1 → 10.0.2.15 (example)
- VM2 → 10.0.2.16 (example)

---

# **8. Ping and Verify the Connection**

Test if the VMs can talk:

From VM1:
```bash
ping <IP address of VM2>

From VM2:
```bash
ping <IP address of VM1>


# **9. (Optional Advanced Setup)**
If you want **more complex network virtualization**:
- **Install a router VM** (like VyOS or pfSense) → connect multiple Internal Networks.
- **Set up static IP addresses** manually on VMs.
- **Configure DHCP Server** on one VM to automatically assign IPs.

Example commands to set static IP:
```bash
sudo nano /etc/netplan/00-installer-config.yaml
# Set IP address manually
```
then
```bash
sudo netplan apply
```
