#include "mbed.h"

#include "pinmap.h"
#include "PeripheralPins.h"
#include "nu_modutil.h"

#define MYCONF_TRAN_UNIT_T          uint8_t
#define MYCONF_BITS_TRAN_UNIT_T     (sizeof (MYCONF_TRAN_UNIT_T) * 8)
#define MYCONF_DMA_USAGE            DMA_USAGE_NEVER
//DMA_USAGE_NEVER,DMA_USAGE_ALWAYS
#define MYCONF_DEBUG                1

// SPI
#define MYCONF_SPI_AUTOSS           1
// NOTE: CS# Deselect Time (tSHSL)
#define MYCONF_SPI_ECHO_PLUS        5
// I2C
#define MYCONF_I2C_ADDR             (0x90)


#if defined(TARGET_NUMAKER_PFM_NUC472)
//Serial
#define MYSERIAL_INST1_RX   PF_0
#define MYSERIAL_INST1_TX   PD_15
#define MYSERIAL_INST1_CTS  PD_13
#define MYSERIAL_INST1_RTS  PD_14
// SPI
#define MYSPI_INST1_MOSI    PF_0
#define MYSPI_INST1_MISO    PD_15
#define MYSPI_INST1_SCLK    PD_14
#define MYSPI_INST1_SSEL    PD_13
#define MYCONF_SPI_tSHSL_US 0

// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
// InterruptIn
#define MYBTN_INST1         SW1
#define MYBTN_INST2         SW2

#elif defined(TARGET_NUMAKER_PFM_M453)
//Serial
#define MYSERIAL_INST1_RX   A2
#define MYSERIAL_INST1_TX   A3
#define MYSERIAL_INST1_CTS  A4
#define MYSERIAL_INST1_RTS  A5
// SPI
#define MYSPI_INST1_MOSI    PD_13
#define MYSPI_INST1_MISO    PD_14
#define MYSPI_INST1_SCLK    PD_15
#define MYSPI_INST1_SSEL    PD_12
#define MYCONF_SPI_tSHSL_US 0

// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
// InterruptIn
#define MYBTN_INST1         SW2
#define MYBTN_INST2         SW3

#elif defined(TARGET_NUMAKER_PFM_M487)  \
    || defined(TARGET_NUMAKER_IOT_M487)
//Serial
#define MYSERIAL_INST1_RX   D13
#define MYSERIAL_INST1_TX   D10
#define MYSERIAL_INST1_CTS  D12
#define MYSERIAL_INST1_RTS  D11
// SPI
#if 1
#define MYSPI_INST1_MOSI    D11
#define MYSPI_INST1_MISO    D12
#define MYSPI_INST1_SCLK    D1
#define MYSPI_INST1_SSEL    D0
#else
#define MYSPI_INST1_MOSI    ((PinName) NU_PINNAME_BIND(PA_0, SPI_1))    //D11
#define MYSPI_INST1_MISO    ((PinName) NU_PINNAME_BIND(PA_1, SPI_1))    //D12
#define MYSPI_INST1_SCLK    ((PinName) NU_PINNAME_BIND(PA_2, SPI_1))    //D13
#define MYSPI_INST1_SSEL    ((PinName) NU_PINNAME_BIND(PA_3, SPI_1))    //D10 
#endif
#define MYCONF_SPI_tSHSL_US 10
// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
#define MYI2C_INST2_SDA     D11
#define MYI2C_INST2_SCL     D12
// InterruptIn
#define MYBTN_INST1         SW2
#define MYBTN_INST2         SW3

#elif defined(TARGET_NUMAKER_IOT_M467)
//Serial
#define MYSERIAL_INST1_RX   D13
#define MYSERIAL_INST1_TX   D10
#define MYSERIAL_INST1_CTS  D12
#define MYSERIAL_INST1_RTS  D11
// SPI
#define MYSPI_INST1_MOSI    D11
#define MYSPI_INST1_MISO    D12
#define MYSPI_INST1_SCLK    D13
#define MYSPI_INST1_SSEL    D10
#define MYCONF_SPI_tSHSL_US 10
// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
#define MYI2C_INST2_SDA     D0
#define MYI2C_INST2_SCL     D1

// InterruptIn
#define MYBTN_INST1         BUTTON1
#define MYBTN_INST2         BUTTON2

#elif defined(TARGET_NUMAKER_PFM_NANO130)
//Serial
#define MYSERIAL_INST1_RX   D0
#define MYSERIAL_INST1_TX   D1
#define MYSERIAL_INST1_CTS  PB_7
#define MYSERIAL_INST1_RTS  PB_6
// SPI
#define MYSPI_INST1_MOSI    D11
#define MYSPI_INST1_MISO    D12
#define MYSPI_INST1_SCLK    D13
#define MYSPI_INST1_SSEL    D10
// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
// InterruptIn
#define MYBTN_INST1         SW1
#define MYBTN_INST2         SW2

#elif defined(TARGET_NUMAKER_PFM_M2351)
//Serial
#define MYSERIAL_INST1_RX   D13
#define MYSERIAL_INST1_TX   D10
#define MYSERIAL_INST1_CTS  D12
#define MYSERIAL_INST1_RTS  D11
// SPI
#define MYSPI_INST1_MOSI    D11
#define MYSPI_INST1_MISO    D12
#define MYSPI_INST1_SCLK    D13
#define MYSPI_INST1_SSEL    D10 
#define MYCONF_SPI_tSHSL_US 10
// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
#define MYI2C_INST2_SDA     D7
#define MYI2C_INST2_SCL     D6
// InterruptIn
#define MYBTN_INST1         SW2
#define MYBTN_INST2         SW3

#elif defined(TARGET_NUMAKER_M252KG)
//Serial
#define MYSERIAL_INST1_RX   D13
#define MYSERIAL_INST1_TX   D10
#define MYSERIAL_INST1_CTS  D12
#define MYSERIAL_INST1_RTS  D11
// SPI
#define MYSPI_INST1_MOSI    D11
#define MYSPI_INST1_MISO    D12
#define MYSPI_INST1_SCLK    D13
#define MYSPI_INST1_SSEL    D10 
#define MYCONF_SPI_tSHSL_US 10
// I2C
#define MYI2C_INST1_SDA     D14
#define MYI2C_INST1_SCL     D15
#define MYI2C_INST2_SDA     D7
#define MYI2C_INST2_SCL     D6
// InterruptIn
// No buttons on-board

#endif

class MyRawSerial: public SerialBase
{
public:
    MyRawSerial(
        PinName tx,
        PinName rx,
        int baud = MBED_CONF_PLATFORM_DEFAULT_SERIAL_BAUD_RATE
    ): SerialBase(tx, rx, baud)
    {
    }

    int getc()
    {
        return _base_getc();
    }

    int putc(int c)
    {
        return _base_putc(c);
    }
};
    
static void test_serial_tx_attach(void);
static void test_serial_rx_attach(void);
static void test_serial_txrx_attach(void);
static void serial_tx_callback(MyRawSerial *serial);
static void serial_rx_callback(MyRawSerial *serial);
static void test_serial_tx_async(void);
static void test_serial_rx_async(void);
static void test_serial_tx_async_n_tx_attach(void);
static void test_serial_rtscts_master(void);
static void test_serial_rtscts_slave(void);
static void serial_async_callback(int event);
static void test_spi_master(void);
static void test_spi_master_async(void);
static void spi_master_async_callback(int event);
static void test_spi_slave(void);
static void test_i2c_master(void);
static void test_i2c_master_async(void);
static void i2c_master_async_callback(int event);
static void test_i2c_slave(void);
static void test_i2c_loopback(void);
static void i2c_master_run(I2C &i2c_master);
static void i2c_master_run(I2C *i2c_master_p);
static void i2c_slave_run(I2CSlave &i2c_slave);
static void i2c_slave_run(I2CSlave *i2c_slave_p);
static void test_interruptin(void);
static void my_gpio_irq_rise(void);
static void my_gpio_irq_fall(void);

static DigitalOut led1(LED1, 1);

// I2C test buffer
struct {
    struct {
        char buf[32];
        char buf2[32];
    } master;
    struct {
        char buf[32];
    } slave;
} i2c_test_ctx;

// SPI test buffer
struct {
    MYCONF_TRAN_UNIT_T buf[32];
    //MYCONF_TRAN_UNIT_T buf2[32];
    StaticCacheAlignedBuffer<MYCONF_TRAN_UNIT_T, 32> buf2;
} spi_test_ctx;

volatile int callback_event = 0;

#if MYCONF_DEBUG
int MY_BUF[64];
int MY_BUF_POS = 0;
#endif

int main()
{
    //test_serial_tx_attach();
    //test_serial_rx_attach();
    //test_serial_txrx_attach();
    //test_serial_tx_async();
    //test_serial_rx_async();
    //test_serial_tx_async_n_tx_attach();
    //test_serial_rtscts_master();
    //test_serial_rtscts_slave();
    //test_spi_master();
    //test_spi_master_async();
    //test_spi_slave();
    //test_i2c_master();
    //test_i2c_master_async();
    //test_i2c_slave();
    test_i2c_loopback();
    //test_interruptin();
}

#if 1
static char serial_buf_tx[] = "123456780000000000111111111122222222223333333333444444444455555555556666666666q";
#elif 0
static char serial_buf_tx[25] = "12345678901234567890\r\n\r\n";
#else
static char serial_buf_tx[13] = "1234567890\r\n";
#endif
static char serial_buf_rx[25];
Semaphore my_serial_sem(0);
static volatile int my_serial_event = 0;

static void test_serial_tx_attach(void)
{
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    
    Callback<void()> callback(&serial_tx_callback, &my_serial);
    my_serial.attach(callback, mbed::SerialBase::TxIrq);
    
    while (1) {
        my_serial.putc('.');
        ThisThread::sleep_for(1000ms);
    }
}

static void test_serial_rx_attach(void)
{
    // NOTE: Use MyRawSerial instead of Serial to be able to call putc/getc in interrupt context.
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    
    Callback<void()> callback(&serial_rx_callback, &my_serial);
    my_serial.attach(callback, mbed::SerialBase::RxIrq);
    
    while (1) {
        ThisThread::sleep_for(1000ms);
    }
}

static void test_serial_txrx_attach(void)
{
    // NOTE: Use MyRawSerial instead of Serial to be able to call putc/getc in interrupt context.
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    
    Callback<void()> tx_callback(&serial_tx_callback, &my_serial);
    Callback<void()> rx_callback(&serial_rx_callback, &my_serial);  
    my_serial.attach(tx_callback, mbed::SerialBase::TxIrq);
    my_serial.attach(rx_callback, mbed::SerialBase::RxIrq);
    
    while (1) {
        ThisThread::sleep_for(1000ms);
    }
}

static void serial_tx_callback(MyRawSerial *serial)
{
    led1 = ! led1;
}

static void serial_rx_callback(MyRawSerial *serial)
{
    // NOTE: Use MyRawSerial instead of Serial to be able to call putc/getc in interrupt context.
    // NOTE: On Nuvoton targets, no H/W IRQ to match RxIrq. Simulation of RxIrq requires the call to Serial::getc().
    serial->putc(serial->getc());
}

static void test_serial_tx_async(void)
{   
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    event_callback_t event_callback(serial_async_callback);
    int32_t sem_tokens;
    
REPEAT:
    sem_tokens = 0;
    my_serial_event = 0;
    my_serial.set_dma_usage_tx(DMA_USAGE_NEVER);
    //my_serial.set_dma_usage_tx(DMA_USAGE_ALWAYS);
    
    my_serial.write((const uint8_t *) serial_buf_tx, sizeof (serial_buf_tx) - 1, event_callback, SERIAL_EVENT_TX_ALL);
    
    sem_tokens = my_serial_sem.try_acquire_for(3000ms);
    if (sem_tokens < 1) {
        printf("Serial Tx async test FAILED with Semaphore.try_acquire_for(): %d\r\n", sem_tokens);
    }
    else {
        if (my_serial_event & SERIAL_EVENT_TX_COMPLETE) {
            printf("Serial Tx async test PASSED\r\n");
            goto REPEAT;
        }
        else {
            printf("Serial Tx async test FAILED with serial event: %d\r\n", my_serial_event);
        }
    }
}

static void test_serial_rx_async(void)
{   
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    event_callback_t event_callback(serial_async_callback);
    int32_t sem_tokens;
    
REPEAT:
    sem_tokens = 0;
    my_serial_event = 0;
    memset(serial_buf_rx, 0x00, sizeof (serial_buf_rx));
    my_serial.set_dma_usage_tx(DMA_USAGE_NEVER);
    //my_serial.set_dma_usage_rx(DMA_USAGE_ALWAYS);
    
    my_serial.read((uint8_t *) serial_buf_rx, sizeof (serial_buf_rx) - 1, event_callback, SERIAL_EVENT_RX_ALL, SERIAL_RESERVED_CHAR_MATCH);    
    //my_serial.read((uint8_t *) serial_buf_rx, sizeof (serial_buf_rx) - 1, event_callback, SERIAL_EVENT_RX_ALL, 'q');
    
    sem_tokens = my_serial_sem.try_acquire_for(10s);
    if (sem_tokens < 1) {
        printf("Serial Rx async test FAILED with Semaphore.try_acquire_for(): %d\r\n", sem_tokens);
    }
    else {
        if (my_serial_event & SERIAL_EVENT_RX_COMPLETE) {
            serial_buf_rx[sizeof (serial_buf_rx) - 1] = 0;
            printf("%s\r\n", serial_buf_rx);
            goto REPEAT;
        }
        if (my_serial_event & SERIAL_EVENT_RX_OVERRUN_ERROR) {
            printf("SERIAL_EVENT_RX_OVERRUN_ERROR\r\n");
        }
        if (my_serial_event & SERIAL_EVENT_RX_FRAMING_ERROR) {
            printf("SERIAL_EVENT_RX_FRAMING_ERROR\r\n");
        }
        if (my_serial_event & SERIAL_EVENT_RX_PARITY_ERROR) {
            printf("SERIAL_EVENT_RX_PARITY_ERROR\r\n");
        }
        if (my_serial_event & SERIAL_EVENT_RX_OVERFLOW) {
            printf("SERIAL_EVENT_RX_OVERFLOW\r\n");
        }
        if (my_serial_event & SERIAL_EVENT_RX_CHARACTER_MATCH) {
            printf("%s\r\n", serial_buf_rx);
            goto REPEAT;
        }
    }
}

void test_serial_tx_async_n_tx_attach(void)
{
    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    
    Callback<void()> callback(&serial_tx_callback, &my_serial);
    my_serial.attach(callback, mbed::SerialBase::TxIrq);
    
    event_callback_t event_callback(serial_async_callback);
    int32_t sem_tokens;
    
REPEAT:
    ThisThread::sleep_for(1000ms);
    
    my_serial.putc('.');
    // Wait for UART TX FIFO empty
    ThisThread::sleep_for(100ms);
    
    sem_tokens = 0;
    my_serial_event = 0;
    my_serial.set_dma_usage_tx(DMA_USAGE_NEVER);
    //my_serial.set_dma_usage_tx(DMA_USAGE_ALWAYS);
    
    my_serial.write((const uint8_t *) serial_buf_tx, sizeof (serial_buf_tx) - 1, event_callback, SERIAL_EVENT_TX_ALL);
    
    sem_tokens = my_serial_sem.try_acquire_for(3000ms);
    if (sem_tokens < 1) {
        printf("Serial tx attach/tx async test FAILED with Semaphore.try_acquire_for(): %d\r\n", sem_tokens);
    }
    else {
        if (my_serial_event & SERIAL_EVENT_TX_COMPLETE) {
            printf("Serial tx attach/tx async test PASSED\r\n");
            goto REPEAT;
        }
        else {
            printf("Serial tx attach/tx async test FAILED with serial event: %d\r\n", my_serial_event);
        }
    }
}

/* For serial RTS/CTS test, we must follow the steps in order:
 *
 * 1. On host, prepare two consoles and connect them to serial master/slave respectively.  
 * 2. On devices, run serial master/slave respectively.
 *    They both would pause at getchar. The order of which to run first is not significant here.
 *    At this time, both serial master/slave's serial are not initialized yet. This is to avoid
 *    interference with each other's current serial by previous serial.
 * 3. Press any key on the console connecting to serial slave to let it continue. This has the following
 *    purposes:
 *    (1) Avoid premature data transfer from serial master
 *    (2) Enable serial slave's RTS/CTS flow control first.
 * 4. Press any key on the console connecting to serial master to let it continue.
 */

void test_serial_rtscts_master(void)
{
    printf("Serial RTS/CTS test (master side)...\r\n");
    printf("Press any char to start...\r\n");
    getchar();

    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    event_callback_t event_callback(serial_async_callback);
    int32_t sem_tokens;
    
    sem_tokens = 0;
    my_serial_event = 0;
#if 1
    my_serial.set_dma_usage_tx(DMA_USAGE_NEVER);
#else
    my_serial.set_dma_usage_tx(DMA_USAGE_ALWAYS);
#endif
    
    my_serial.set_flow_control(MyRawSerial::RTSCTS, MYSERIAL_INST1_RTS, MYSERIAL_INST1_CTS);

    my_serial.write((const uint8_t *) serial_buf_tx, sizeof (serial_buf_tx) - 1, event_callback, SERIAL_EVENT_TX_ALL);
    sem_tokens = my_serial_sem.try_acquire_for(10s);
    if (sem_tokens < 1) {
        printf("Serial RTS/CTS test FAILED with Semaphore.try_acquire_for(): %d\r\n", sem_tokens);
    }
    else {
        if (my_serial_event & SERIAL_EVENT_TX_COMPLETE) {
            printf("Serial RTS/CTS test PASSED\r\n");
        }
        else {
            printf("Serial RTS/CTS test FAILED with serial event: %d\r\n", my_serial_event);
        }
    }
}

void test_serial_rtscts_slave(void)
{
    printf("Serial RTS/CTS test (slave side)...\r\n");
    printf("Press any char to start...\r\n");
    getchar();

    static MyRawSerial my_serial(MYSERIAL_INST1_TX, MYSERIAL_INST1_RX);
    event_callback_t event_callback(serial_async_callback);
    int32_t sem_tokens;

#if 1
    my_serial.set_dma_usage_tx(DMA_USAGE_NEVER);
#else
    my_serial.set_dma_usage_rx(DMA_USAGE_ALWAYS);
#endif

    my_serial.set_flow_control(MyRawSerial::RTSCTS, MYSERIAL_INST1_RTS, MYSERIAL_INST1_CTS);

    while (1) {
        sem_tokens = 0;
        my_serial_event = 0;
        memset(serial_buf_rx, 0x00, sizeof (serial_buf_rx));

        /* Assume serial_buf_tx ends with 'q'
         * 
         * Without char_match, we could have the last my_serial.read unfinished because it doesn't
         * receive enough characters from serial_buf_tx.
         * 
         * With char_match set to 'q', we could get full serial_buf_tx before 'q'.
         */
#if 0
        my_serial.read((uint8_t *) serial_buf_rx, sizeof (serial_buf_rx) - 1, event_callback, SERIAL_EVENT_RX_ALL, SERIAL_RESERVED_CHAR_MATCH);
#else
        my_serial.read((uint8_t *) serial_buf_rx, sizeof (serial_buf_rx) - 1, event_callback, SERIAL_EVENT_RX_ALL, 'q');
#endif

        sem_tokens = my_serial_sem.try_acquire_for(10s);
        if (sem_tokens < 1) {
            printf("Semaphore.try_acquire_for failed with Semaphore.try_acquire_for(): %d\r\n", sem_tokens);
        }
        else {
            if (my_serial_event & SERIAL_EVENT_RX_COMPLETE) {
                printf("%s\r\n", serial_buf_rx);
            }
            else if (my_serial_event & SERIAL_EVENT_RX_CHARACTER_MATCH) {
                printf("%s\r\n", serial_buf_rx);
            }
            else {
                printf("Serial RTS/CTS test FAILED with serial event: %d\r\n", my_serial_event);
            }
        }
        
        /* With RTS/CTS flow control enabled, we shouldn't get serial rx FIFO overflow due to the wait. */
        ThisThread::sleep_for(1000ms);
    }
}

void serial_async_callback(int event)
{
    my_serial_event = event;
    my_serial_sem.release();
}

#if DEVICE_SPI

/* Trouble-shooting SPI test failure
 *
 * SPI test is easily to fail than other buses. If that happens, try the following fixes:
 * 1. Lower SPI bus clock to e.g. 100 KHz
 * 2. Better DuPont line (especially for CLK/MOSI/MISO)
 *    (1) The shorter the better
 *    (2) Resistor-serialized
 * 3. More ground lines between test boards
 */

static void test_spi_master(void)
{
#if MYCONF_SPI_AUTOSS
    static SPI spi_master(MYSPI_INST1_MOSI, MYSPI_INST1_MISO, MYSPI_INST1_SCLK, MYSPI_INST1_SSEL);
#else
    static SPI spi_master(MYSPI_INST1_MOSI, MYSPI_INST1_MISO, MYSPI_INST1_SCLK);
    static DigitalOut cs(MYSPI_INST1_SSEL);
#endif

    int n_round = 0;
    int data = 0;
    int res = 0;
    
    // NOTE: With NUMAKER_PFM_NUC472/NUMAKER_PFM_M2351 as SPI slave, test fails with default 1 MHz SPI clock.
    spi_master.frequency(100000);

    spi_master.format(MYCONF_BITS_TRAN_UNIT_T);    // n bits per SPI frame
    
    // NOTE: Run spi_master first and then run spi_slave 3 secs. This is to keep cs inactive until spi_slave is ready.
#if (! MYCONF_SPI_AUTOSS)
    cs = 1;
#endif
    ThisThread::sleep_for(3000ms);
	
REPEAT:

    data = 0;
    for (int i = 0; i < 30; i ++) {
#if (! MYCONF_SPI_AUTOSS)
        cs = 0;
#endif
        res = spi_master.write(data);
#if (! MYCONF_SPI_AUTOSS)
        cs = 1;
#endif

        if (i >= 3 && res != (data + MYCONF_SPI_ECHO_PLUS - 3)) {
            printf("i=%d, res=0x%08x, data=0x%08x\r\n", i, res, data);
            printf("%s Round %d FAILED\r\n", __func__, n_round ++);
            while (1);
        }
        
        data ++;
        
#if MYCONF_SPI_tSHSL_US
        wait_us(MYCONF_SPI_tSHSL_US);
#endif
    }

    printf("%s Round %d OK\r\n", __func__, n_round ++);
    goto REPEAT;
}

static void test_spi_master_async(void)
{
#if MYCONF_SPI_AUTOSS
    static SPI spi_master(MYSPI_INST1_MOSI, MYSPI_INST1_MISO, MYSPI_INST1_SCLK, MYSPI_INST1_SSEL);
#else
    static SPI spi_master(MYSPI_INST1_MOSI, MYSPI_INST1_MISO, MYSPI_INST1_SCLK);
    static DigitalOut cs(MYSPI_INST1_SSEL);
#endif

    int n_round = 0;
    
    // NOTE: With NUMAKER_PFM_NUC472/NUMAKER_PFM_M2351 as SPI slave, test fails with default 1 MHz SPI clock.
    spi_master.frequency(100000);
     
    spi_master.set_dma_usage(MYCONF_DMA_USAGE);
    spi_master.format(MYCONF_BITS_TRAN_UNIT_T);    // n bits per SPI frame
    // Fill in transmit buffer
    for (int i = 0; i < sizeof (spi_test_ctx.buf) / sizeof (spi_test_ctx.buf[0]); i ++) {
        spi_test_ctx.buf[i] = i;
    }
    
    /* NOTE: When NUC472/M2351 runs as SPI slave, it cannot handle transmit/receive data in time.
     *       To fix it, SPI master is configured to enlarge suspend interval between
     *       transmit/receive data frames. */
    uint32_t spi_mosi = pinmap_peripheral(MYSPI_INST1_MOSI, PinMap_SPI_MOSI);
    uint32_t spi_miso = pinmap_peripheral(MYSPI_INST1_MISO, PinMap_SPI_MISO);
    uint32_t spi_sclk = pinmap_peripheral(MYSPI_INST1_SCLK, PinMap_SPI_SCLK);
#if MYCONF_SPI_AUTOSS
    uint32_t spi_ssel = pinmap_peripheral(MYSPI_INST1_SSEL, PinMap_SPI_SSEL);
#else
    uint32_t spi_ssel = NC;
#endif
    uint32_t spi_data = pinmap_merge(spi_mosi, spi_miso);
    uint32_t spi_cntl = pinmap_merge(spi_sclk, spi_ssel);
    uint32_t spi_perif = pinmap_merge(spi_data, spi_cntl);
    MBED_ASSERT((int) spi_perif != NC);
    SPI_T *spi_base = (SPI_T *) NU_MODBASE(spi_perif);
#if defined(TARGET_NUMAKER_PFM_NANO130)
    spi_base->CTL = (spi_base->CTL & ~SPI_CTL_SP_CYCLE_Msk) | SPI_CTL_SP_CYCLE_Msk;
#else
    spi_base->CTL = (spi_base->CTL & ~SPI_CTL_SUSPITV_Msk) | SPI_CTL_SUSPITV_Msk;
#endif
    printf("SPI_T::CTL: %08X\r\n", spi_base->CTL);

    // NOTE: Run spi_master first and then run spi_slave 3 secs. This is to keep cs inactive until spi_slave is ready.
#if (! MYCONF_SPI_AUTOSS)
    cs = 1;
#endif
    ThisThread::sleep_for(3000ms);

REPEAT:

    // Clear receive buffer
    memset(spi_test_ctx.buf2.data(), 0xFF,  spi_test_ctx.buf2.capacity() * sizeof(spi_test_ctx.buf2[0]));
    
#if (! MYCONF_SPI_AUTOSS)
    cs = 0;
#endif

    callback_event = 0;
    event_callback_t callback(spi_master_async_callback);
    // NOTE: Check transfer length in bytes or in words
    if (spi_master.transfer((const MYCONF_TRAN_UNIT_T *) (spi_test_ctx.buf), sizeof (spi_test_ctx.buf), spi_test_ctx.buf2, spi_test_ctx.buf2.capacity() * sizeof(spi_test_ctx.buf2[0]), callback, SPI_EVENT_ALL)) {
        printf("%s FAILED\r\n", __func__);
#if (! MYCONF_SPI_AUTOSS)
        cs = 1;
#endif
        while (1);
    }
    
    // Wait for asynchronous transfer done
    while (callback_event == 0);
    
#if (! MYCONF_SPI_AUTOSS)
    cs = 1;
#endif

    if (callback_event & SPI_EVENT_ERROR) {
        printf("SPI_EVENT_ERROR\r\n");
        while (1);
    }
    if (callback_event & SPI_EVENT_RX_OVERFLOW) {
        printf("SPI_EVENT_RX_OVERFLOW\r\n");
        while (1);
    }
    if (callback_event & SPI_EVENT_COMPLETE) {
        printf("SPI_EVENT_COMPLETE\r\n");
        if (memcmp(spi_test_ctx.buf + MYCONF_SPI_ECHO_PLUS, spi_test_ctx.buf2.data() + 3, sizeof (spi_test_ctx.buf) - sizeof (MYCONF_TRAN_UNIT_T) * MYCONF_SPI_ECHO_PLUS)) {
            printf("%s Round %d FAILED\r\n", __func__, n_round ++);
            while (1);
        }
        else {
            printf("%s Round %d OK\r\n", __func__, n_round ++);
            goto REPEAT;
        }
    }
}

static void spi_master_async_callback(int event)
{
    callback_event = event;
}

static void test_spi_slave(void)
{
    static SPISlave spi_slave(MYSPI_INST1_MOSI, MYSPI_INST1_MISO, MYSPI_INST1_SCLK, MYSPI_INST1_SSEL);
    int resp = -1;

    spi_slave.format(MYCONF_BITS_TRAN_UNIT_T);              // n bits per SPI frame
    // NOTE: 
    // As STATUS[SLVURIF] is set, next data in transmit buffer are not transmitted correctly:
    // On NUC472, next data in transmit buffer can be transmitted out but is incorrect.
    // On M453, next data in transmit buffer cannot be transmitted out until next CS select/deselect. Clear this flag doesn't recover.
    spi_slave.reply(resp);                                  // Prime SPI with first reply
    spi_slave.reply(resp);                                  // Prime SPI with first reply
    spi_slave.reply(resp);                                  // Prime SPI with first reply

    while(1) {
        if (spi_slave.receive()) {
            resp = spi_slave.read();                        // Read byte from master
#if MYCONF_DEBUG
            if (MY_BUF_POS < sizeof (MY_BUF) / sizeof (MY_BUF[0])) {
                MY_BUF[MY_BUF_POS ++] = resp;
            }
#endif
            
            spi_slave.reply(resp + MYCONF_SPI_ECHO_PLUS);   // Make this the next reply
        }
    }
}

#endif  // #if DEVICE_SPI

#if DEVICE_I2C

static void test_i2c_master(void)
{
    static I2C i2c_master(MYI2C_INST1_SDA, MYI2C_INST1_SCL);

    i2c_master_run(i2c_master);
}

static void test_i2c_master_async(void)
{
    static I2C i2c_master(MYI2C_INST1_SDA, MYI2C_INST1_SCL);
    
    int n_round = 0;

    // Fill in transmit buffer
    for (int i = 0; i < sizeof (i2c_test_ctx.master.buf) / sizeof (i2c_test_ctx.master.buf[0]); i ++) {
        i2c_test_ctx.master.buf[i] = i;
    }
    
REPEAT:
    // Clear receive buffer
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    
    callback_event = 0;
    event_callback_t callback(i2c_master_async_callback);
    if (i2c_master.transfer(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf, sizeof (i2c_test_ctx.master.buf) / sizeof (i2c_test_ctx.master.buf[0]), i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2) / sizeof (i2c_test_ctx.master.buf2[0]), callback, I2C_EVENT_ALL, 0)) {
        printf("%s FAILED\r\n", __func__);
        while (1);
    }
    
    // Wait for asynchronous transfer done
    while (callback_event == 0);

    if (callback_event & I2C_EVENT_ERROR) {
        printf("I2C_EVENT_ERROR\r\n");
        while (1);
    }
    if (callback_event & I2C_EVENT_ERROR_NO_SLAVE) {
        printf("I2C_EVENT_ERROR_NO_SLAVE\r\n");
        while (1);
    }
    if (callback_event & I2C_EVENT_TRANSFER_EARLY_NACK) {
        printf("I2C_EVENT_TRANSFER_EARLY_NACK\r\n");
        while (1);
    }
    if (callback_event & I2C_EVENT_TRANSFER_COMPLETE) {
        printf("I2C_EVENT_TRANSFER_COMPLETE\r\n");
        if (memcmp(i2c_test_ctx.master.buf + 1, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf) - sizeof (char) * 1)) {
            printf("%s Round %d FAILED\r\n", __func__, n_round ++);
            while (1);
        }
        else {
            printf("%s Round %d OK\r\n", __func__, n_round ++);
            goto REPEAT;
        }
    }
}

static void i2c_master_async_callback(int event)
{
    callback_event = event;
}

static void test_i2c_slave(void)
{
    static I2CSlave i2c_slave(MYI2C_INST1_SDA, MYI2C_INST1_SCL);

    i2c_slave_run(i2c_slave);
}

#if defined(MYI2C_INST2_SDA) && defined(MYI2C_INST2_SCL)
static void test_i2c_loopback(void)
{
    static I2C i2c_master(MYI2C_INST1_SDA, MYI2C_INST1_SCL);
    static I2CSlave i2c_slave(MYI2C_INST2_SDA, MYI2C_INST2_SCL);

    static Thread thread_i2c_master;
    static Thread thread_i2c_slave;

    /* Per test, let I2C slave go first then I2C master, or failed */
    thread_i2c_slave.start(callback(i2c_slave_run, &i2c_slave));
    ThisThread::sleep_for(100ms);
    thread_i2c_master.start(callback(i2c_master_run, &i2c_master));

    while (1) {
        ThisThread::sleep_for(5s);
    }

    thread_i2c_master.join();
    thread_i2c_slave.join();
}
#endif

static void i2c_master_run(I2C &i2c_master)
{
    int n_round = 0;
    
    // Fill in transmit buffer
    for (int i = 0; i < sizeof (i2c_test_ctx.master.buf) / sizeof (i2c_test_ctx.master.buf[0]); i ++) {
        i2c_test_ctx.master.buf[i] = i;
    }

REPEAT:
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf, sizeof (i2c_test_ctx.master.buf), 1);
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2), 1);
    
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2), 1);
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2), 1);
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2), 1);
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2), 1);
    
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    
    i2c_master.write(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    memset(i2c_test_ctx.master.buf2, 0xFF, sizeof (i2c_test_ctx.master.buf2));
    i2c_master.read(MYCONF_I2C_ADDR, i2c_test_ctx.master.buf2, sizeof (i2c_test_ctx.master.buf2));
    
    char *buf_pos = i2c_test_ctx.master.buf;
    char *buf_end = i2c_test_ctx.master.buf + sizeof (i2c_test_ctx.master.buf) / sizeof (i2c_test_ctx.master.buf[0]);
    char *buf2_pos = i2c_test_ctx.master.buf2;
    int data;
    int data2;
    while (buf_pos < buf_end) {
        data = *buf_pos ++;
        data2 = *buf2_pos ++;
        if (data2 != (data + 5)) {
            printf("%s Round %d FAILED\r\n", __func__, n_round ++);
            while (1);
        }
    }

    printf("%s Round %d OK\r\n", __func__, n_round ++);
    goto REPEAT;
}

static void i2c_master_run(I2C *i2c_master_p)
{
    i2c_master_run(*i2c_master_p);
}

static void i2c_slave_run(I2CSlave &i2c_slave)
{
    i2c_slave.address(MYCONF_I2C_ADDR);

    while (1) {
        int addr_status = i2c_slave.receive();
        switch (addr_status) {
            case I2CSlave::ReadAddressed:
                i2c_slave.write(i2c_test_ctx.slave.buf, sizeof (i2c_test_ctx.slave.buf));
                break;
            case I2CSlave::WriteAddressed:
                i2c_slave.read(i2c_test_ctx.slave.buf, sizeof (i2c_test_ctx.slave.buf));
                for(int i = 0; i < sizeof (i2c_test_ctx.slave.buf); i ++) {
                    i2c_test_ctx.slave.buf[i] ++;
                }
                break;
        }
    }
}

static void i2c_slave_run(I2CSlave *i2c_slave_p)
{
    i2c_slave_run(*i2c_slave_p);
}

#endif  // #if DEVICE_I2C

#if defined(MYBTN_INST1) && defined(MYBTN_INST2)
static void test_interruptin(void)
{
    static InterruptIn int_in1(MYBTN_INST1);
    static InterruptIn int_in2(MYBTN_INST2);

    //TESTTEST
    //int_in1.mode(Quasi);
    //int_in2.mode(Quasi);
    
    int_in1.rise(my_gpio_irq_rise);
    int_in1.fall(my_gpio_irq_fall);
    
    int_in2.rise(my_gpio_irq_rise);
    int_in2.fall(my_gpio_irq_fall);
}
#endif

static void my_gpio_irq_rise(void)
{
    led1 = ! led1;
    //printf("Detected GPIO IRQ Rise\r\n");
}
static void my_gpio_irq_fall(void)
{
    led1 = ! led1;
    //printf("Detected GPIO IRQ Fall\r\n");
}
